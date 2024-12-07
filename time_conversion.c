#include "time_conversion.h"


void convert_to_hours(int seconds, int *hours) {
    *hours = seconds / 3600;
}


void convert_to_minutes(int seconds, int *minutes) {
    *minutes = (seconds % 3600) / 60;
}


void convert_to_seconds(int seconds, int *remaining_seconds) {
    *remaining_seconds = seconds % 60;
}

