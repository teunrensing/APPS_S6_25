# FreeRTOS Architecture Overview - Voice Trainer Project

## Summary
This project implements a multi-task real-time system using FreeRTOS on ESP32-S3 for a voice training device with alarm functionality. The architecture uses task-based concurrency with inter-task communication via queues and mutexes.

---

## Core Components

### 1. **FreeRTOS Wrapper** [include/freertos_wrapper.h]
Minimal wrapper that includes essential FreeRTOS headers:
- `FreeRTOS.h` - Core kernel
- `task.h` - Task management
- `queue.h` - Queue management

---

## Global Queues & Synchronization

### Mode Change Queue
- **Name**: `mode_change_queue`
- **Type**: `QueueHandle_t`
- **Size**: 5 items
- **Item Type**: `AppMode` (enum)
- **Purpose**: Routes application mode changes (HOME, VOICE_TRAINER, PILL_ALARM, SLEEP_ALARM)
- **Initialized in**: `main.cpp:setup()`

### Logging Queue
- **Name**: `log_queue`
- **Type**: `QueueHandle_t`
- **Size**: 10 items
- **Item Type**: `char[128]` string buffer
- **Purpose**: Thread-safe serial logging via queue
- **Initialized in**: `main.cpp:setup()`

### MP3 Player Mutex
- **Name**: `mp3Mutex`
- **Type**: `SemaphoreHandle_t` (binary mutex)
- **Scope**: Static in `mp3_player.cpp`
- **Purpose**: Protects MP3 module I/O operations
- **Initialized in**: `init_mp3()`

---

## Task Hierarchy & Initialization

### Initialization Sequence (setup())

```
setup() [main.cpp:18]
├── init_display()
├── ui_init()
├── init_mp3()
├── i2cInit()
├── button_init()
├── init_home_button()
├── Create global queues
│   ├── mode_change_queue (5 items, AppMode)
│   └── log_queue (10 items, char[128])
└── Start system tasks
    ├── start_display_task()
    ├── start_button_task()
    ├── start_logger_task()
    ├── start_time_task()
    ├── start_alarms_task()
    └── start_mode_controller_task()
```

### Main System Tasks (Always Running)

#### **1. Display Task** [display.cpp:114]
- **Task Name**: "Display"
- **Stack Size**: 8192 bytes
- **Priority**: 1
- **Handle**: Not stored
- **Function**: `display_task()`
- **Purpose**: Renders UI using LittleVGL to ILI9488 display
- **Communication**: Receives UI updates from mode-specific tasks

#### **2. Button Tasks** [buttons.cpp:79-80]
Multiple queue-based tasks for button input handling:

**i2c_write_task**
- **Task Name**: "i2c_write_task"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Function**: `i2c_write_task()`
- **Local Queue**: `button_tx_queue`
- **Purpose**: Sends button commands to secondary MCU via I2C

**i2c_read_task**
- **Task Name**: "i2c_read_task"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Function**: `i2c_read_task()`
- **Local Queue**: `button_rx_queue`
- **Purpose**: Receives button events from secondary MCU via I2C

**Queue Structure**:
- `button_tx_queue`: 10 items, `button_cmd_t` (button name + display icon)
- `button_rx_queue`: 10 items, `button_cmd_t`

#### **3. Logger Task** [logger.cpp:18]
- **Task Name**: "Logger"
- **Stack Size**: 2048 bytes
- **Priority**: 1
- **Function**: `logger_task()`
- **Queue Input**: `log_queue`
- **Purpose**: Dequeues log messages and prints to Serial
- **Pattern**: Blocking receive with `portMAX_DELAY`

#### **4. Time Task** [time_utils.cpp:105]
- **Task Name**: "TimeTask"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Function**: `time_task()`
- **Purpose**: Maintains system time and scheduling
- **Used by**: Alarm system and sleep scheduling

#### **5. Alarm Task** [alarms.cpp:142]
- **Task Name**: "Buttons"
- **Stack Size**: 2048 bytes
- **Priority**: 1
- **Handle**: `alarm_task_handle`
- **Function**: `alarm_task()`
- **Purpose**: Manages alarm state and scheduling
- **Subtasks**:
  - Sleep alarm handler: `start_sleep_alarm()` [sleep_alarm.cpp:22]
  - Pill alarm handler: `start_pill_alarm()` [pill_alarm.cpp:32]

#### **6. Mode Controller Task** [mode_controller.cpp:57]
- **Task Name**: "ModeController"
- **Stack Size**: 2048 bytes
- **Priority**: 1
- **Function**: `mode_controller_task()`
- **Queue Input**: `mode_change_queue`
- **Purpose**: **Central orchestrator** - manages mode transitions
- **Behavior**:
  - Listens on `mode_change_queue`
  - Stops current mode tasks: `stop_mode_tasks(currentMode)`
  - Starts new mode tasks: `start_mode_tasks(newMode)`
  - Maintains global state: `currentMode`

#### **7. Home Button Task** [home_button.cpp:58]
- **Task Name**: "HomeButtonTask"
- **Stack Size**: Variable (from `init_home_button()`)
- **Priority**: 2 (user-defined)
- **Core**: Pinned to core 0
- **Function**: `homeButtonTask()`
- **Queue Input**: `buttonQueue`
- **ISR Handler**: `homeButtonISR()` (FALLING edge on HOME_BUTTON_PIN)
- **Purpose**: Hardware interrupt handler for home button
- **Behavior**:
  - Debounce: 50ms delay
  - Returns to HOME mode via `change_mode(MODE_HOME)`

---

## Mode-Specific Tasks

### Mode: HOME
**Initiation**: `start_home()` [home.cpp:39]
- **Task Name**: "Home"
- **Stack Size**: 2048 bytes
- **Priority**: 1
- **Handle**: `homeTaskHandle`
- **Function**: `home_task()`
- **Purpose**: Home screen/idle state

**Termination**: `stop_home()`

---

### Mode: VOICE_TRAINER
**Initiation**: `start_voice_trainer()` [voice_trainer.cpp:181-184]
Creates 3 parallel tasks with FFT queue:

**Local Queue**: `fftQueue`
- **Size**: 2 items
- **Item Type**: `int16_t*` (pointer to audio buffer)
- **Purpose**: Passes audio samples from audio task to FFT task

#### **Audio Collection Task**
- **Task Name**: "AudioTask"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Handle**: `audioTaskHandle`
- **Function**: `collect_audio_samples_task()`
- **Purpose**: Reads I2S microphone data in blocks (FFT_SIZE=1024 samples)
- **Behavior**:
  - Alternates between two buffers (`audio_buffer_a`, `audio_buffer_b`)
  - Reads 1024 samples at microphone sample rate
  - Sends buffer pointer to `fftQueue`
  - Runs continuously with `i2s_read()` blocking calls

#### **FFT Processing Task**
- **Task Name**: "FFTTask"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Handle**: `fftTaskHandle`
- **Function**: `fft_task()`
- **Purpose**: Performs frequency analysis and moving average smoothing
- **Behavior**:
  - Receives audio buffers from `fftQueue`
  - Computes FFT using ArduinoFFT library
  - Maintains moving average arrays (20 samples deep)
  - Calculates frequency and amplitude peaks

#### **UI Update Task**
- **Task Name**: "UITrainer"
- **Stack Size**: 2048 bytes
- **Priority**: 1
- **Handle**: `uiTaskHandle`
- **Function**: `update_trainer_ui_task()`
- **Purpose**: Updates display with real-time FFT visualization
- **Behavior**:
  - Renders frequency spectrum graph
  - Updates amplitude bars
  - Handles user interaction during training

**Termination**: `stop_voice_trainer()` - Deletes all three tasks

---

### Mode: PILL_ALARM
**Initiation**: `start_pill_alarm()` [pill_alarm.cpp:32]
- **Task Name**: "pill_alarm"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Handle**: `pillAlarmTaskHandle`
- **Function**: `pill_alarm_task()`
- **Purpose**: Manages pill reminder alarm UI and logic

**Termination**: `stop_pill_alarm()`

---

### Mode: SLEEP_ALARM
**Initiation**: `start_sleep_alarm()` [sleep_alarm.cpp:22]
- **Task Name**: "sleep_alarm"
- **Stack Size**: 4096 bytes
- **Priority**: 1
- **Handle**: `sleepAlarmTaskHandle`
- **Function**: `sleep_alarm_task()`
- **Purpose**: Manages sleep reminder alarm UI and logic

**Termination**: `stop_sleep_alarm()`

---

## Task Communication Diagram

```
                          ┌─────────────────┐
                          │   Home Button   │
                          │  Interrupt (ISR)│
                          └────────┬────────┘
                                   │ xQueueSendFromISR
                                   ▼
                    ┌──────────────────────────┐
                    │ Home Button Task         │
                    │ Debounce + check state   │
                    └─────────────┬────────────┘
                                  │ change_mode()
                                  ▼
                    ┌──────────────────────────┐
                    │ mode_change_queue        │
                    │ (5 items, AppMode)       │
                    └─────────────┬────────────┘
                                  │ xQueueReceive
                                  ▼
                    ┌──────────────────────────┐
                    │ Mode Controller Task     │
                    │ Orchestrates transitions │
                    └────────┬─────┬──┬────────┘
                             │     │  │
                    ┌────────┘     │  └─────────────────┐
                    │              │                    │
                    ▼              ▼                    ▼
              ┌──────────┐   ┌─────────────┐   ┌───────────────┐
              │ HOME     │   │VOICE_TRAINER│   │PILL/SLEEP     │
              │Task      │   │ (3 tasks)   │   │ALARM Tasks    │
              └──────────┘   └─────────────┘   └───────────────┘
                                   │
                                   │ fftQueue
                                   │ (2 items)
                    ┌──────────────┼──────────────┐
                    ▼              ▼              ▼
            ┌─────────────┐ ┌─────────────┐ ┌──────────┐
            │Audio Task   │ │FFT Task     │ │UI Task   │
            │(I2S read)   │ │(Processing) │ │(Display) │
            └─────────────┘ └─────────────┘ └──────────┘

════════════════════════════════════════════════════════════

            ┌──────────────┐
            │ Logger Task  │
            └───────┬──────┘
                    │ log_queue
                    │ (10 items)
                    ▼
            ┌──────────────┐
            │ Serial Print │
            └──────────────┘

════════════════════════════════════════════════════════════

        ┌──────────────────────────────┐
        │ Button I/O Tasks (2 tasks)   │
        │ - I2C Write Task             │
        │ - I2C Read Task              │
        │ (button_tx_queue,            │
        │  button_rx_queue)            │
        └──────────────────────────────┘
                    ▼
            ┌──────────────┐
            │  Secondary   │
            │  MCU (I2C)   │
            └──────────────┘
```

---

## Data Flow Patterns

### 1. **Mode Transitions (Command Pattern)**
```
User Input → Button ISR → Home Button Task → mode_change_queue 
  → Mode Controller → stop_mode_tasks() → start_mode_tasks()
```

### 2. **Voice Training Pipeline (Producer-Consumer)**
```
Microphone (I2S) → Audio Task → fftQueue 
  → FFT Task → (shared memory) → UI Task → Display Task
```

### 3. **Button Input (Queue-Based)**
```
I2C Secondary → i2c_read_task → button_rx_queue 
  → UI Handler → (updates LittleVGL UI)
```

### 4. **Logging (Queue-Based)**
```
Any Task → log_message() → log_queue 
  → Logger Task → Serial.println()
```

### 5. **MP3 Control (Mutex-Protected)**
```
Any Task → xSemaphoreTake(mp3Mutex) 
  → sendCommand() → MP3 Module → xSemaphoreGive()
```

---

## Synchronization Mechanisms

| Mechanism | Type | Usage | Count |
|-----------|------|-------|-------|
| Queue | FreeRTOS | Async message passing | 4 global + 2 voice-trainer-local |
| Mutex | Binary Semaphore | Resource protection (MP3) | 1 |
| Blocking Receive | Task suspend | Wait for queue data | Multiple |
| ISR to Task | Queue + BaseType flag | Hardware interrupt → task | Home button |

---

## Priority Levels

- **Priority 1**: Most system tasks (standard work)
- **Priority 2**: Home button task (user input responsiveness)
- **Default core**: Core 1 (all tasks except home button)
- **Pinned core**: Core 0 (home button task)

---

## Key Design Patterns

### 1. **Mode/State Machine Pattern**
- Central orchestrator (`mode_controller_task`) manages transitions
- Clean startup/shutdown of mode-specific tasks
- Prevents resource conflicts between modes

### 2. **Queue-Based Communication**
- Decouples producers from consumers
- Non-blocking send possible with timeout
- Thread-safe without explicit locks

### 3. **Interrupt-to-Task Bridge**
- ISR signals task via queue
- Task performs debouncing and validation
- Prevents ISR overload

### 4. **Mutex-Protected Resources**
- MP3 module protected by binary semaphore
- Prevents concurrent I/O corruption

---

## Performance Characteristics

### Stack Allocation
- **Largest**: Display Task (8192 bytes)
- **Voice Trainer Audio**: 4096 bytes (I2S buffer + overhead)
- **Smallest**: Logger/Mode Controller (2048 bytes)
- **Total Typical**: ~50KB+ for concurrent voice training

### Queue Throughput
- **Audio**: 1024 samples @ 16kHz = ~64ms per buffer
- **Logging**: Non-critical, up to 10 messages buffered
- **Mode Change**: Immediate queue length of 5

### Latency
- **Button Response**: ~50ms debounce + ISR reaction
- **Display Update**: Governed by `display_task()`
- **FFT Processing**: Per-buffer latency

---

## Critical Sections & Race Conditions

### Protected:
- ✅ MP3 commands (mutex)
- ✅ Global mode state (atomic transition in mode controller)
- ✅ Queue operations (atomic via FreeRTOS)

### Potential Issues:
- ⚠️ Display updates from multiple tasks (needs LittleVGL thread safety)
- ⚠️ Mode transition during I2S read (mitigated by task deletion)

---

## Initialization Order Dependency

1. ✅ Display init (hardware setup)
2. ✅ MP3 init (mutex creation)
3. ✅ Button init (queues)
4. ✅ Queue creation (mode_change_queue, log_queue)
5. ✅ Task creation (establishes scheduler)
6. ✅ Main loop empty (scheduler takes over)

---

## File Dependencies Map

```
freertos_wrapper.h (base)
    ├─ main.cpp (queue/task creation)
    ├─ mode_controller.cpp
    ├─ logger.cpp
    ├─ buttons.cpp
    ├─ voice_trainer.cpp
    ├─ home_button.cpp
    ├─ mp3_player.cpp
    ├─ alarms.cpp
    ├─ display.cpp
    ├─ time_utils.cpp
    ├─ home.cpp
    ├─ sleep_alarm.cpp
    └─ pill_alarm.cpp
```

---

## Summary Table

| Component | Type | Count | Purpose |
|-----------|------|-------|---------|
| Global Queues | Queue | 2 | Mode control, logging |
| Mode-Specific Queues | Queue | 2 (voice trainer) | FFT pipeline |
| Mutexes | Semaphore | 1 | MP3 resource protection |
| System Tasks | Task | 6 | Display, buttons, logger, time, alarms, mode controller |
| Mode Tasks | Task | 3-4 | Varies by active mode |
| ISRs | Hardware | 1 | Home button |

**Total Active Tasks at Startup**: 6 system tasks  
**Max Tasks During Voice Training**: 9 (6 system + 3 voice trainer)

