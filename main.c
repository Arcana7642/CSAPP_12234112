#include <stdio.h>
#include "time_conversion.h"

int main() {
    int total_seconds;
    int hours, minutes, seconds;

    printf("초를 입력하세요: ");
    scanf("%d", &total_seconds);

    convert_to_hours(total_seconds, &hours);
    convert_to_minutes(total_seconds, &minutes);
    convert_to_seconds(total_seconds, &seconds);

    printf("입력한 %d초는 %d시간 %d분 %d초입니다.\n", total_seconds, hours, minutes, seconds);

    return 0;
}

