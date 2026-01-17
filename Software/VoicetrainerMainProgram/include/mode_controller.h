//Takes care of starting different tasks that belong to that mode.
#ifndef MODE_CONTROLLER_H
#define MODE_CONTROLLER_H

#include <mode_config.h>

void start_mode_controller_task();
void start_mode_tasks(AppMode mode);
void stop_mode_tasks(AppMode mode);
void change_mode(AppMode newMode);

#endif
