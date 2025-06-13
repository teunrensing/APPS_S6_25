
#include <stdio.h>

#include <vector>
#include <deque>
#include <string>
#include <queue>


#define DB_CALIBRATION_OFFSET 10
#define HZ_CALIBRATION_OFFSET 5 
#define CALIBRATE_QUEUE_LENGTH 100
#define MIN_CALIBRATIONVALUES_AMOUNT 5 
#define QUEUE_MAX_SIZE 6
#define MIN_PEAK_AMPLITUDE 0.083f

static bool trainerTreshold = true;

void uiTask(void *pvParameters);

void update_ball_position_async(void *param);
/**
 * @brief Reads audio data and updates the global variables accordingly.
 * @param params Unused parameter.
 */
void task_read_audio(void* params);

/**
 * @brief Processes audio data and performs necessary computations.
 * @param params Unused parameter.
 */
void task_process_audio(void *params);

/**
 * @brief Runs the main state machine logic.
 * @param params Unused parameter.
 */
void task_run_statemachine(void *params);

void calibration(int index, std::vector<float> &audio);
void task_calibration(void *params);