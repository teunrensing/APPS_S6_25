//retreives and updates current time.
#ifndef TIME_UTILS_H
#define TIME_UTILS_H

void start_time_task();
void initTime(long, int);

const char* getCurrentHourStr();
const char* getCurrentMinuteStr();
int getCurrentHour();
int getCurrentMinute();

#endif
