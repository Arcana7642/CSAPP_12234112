#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*convert_to_hours)(int, int *);
    void (*convert_to_minutes)(int, int *);
    void (*convert_to_seconds)(int, int *);
    char *error;

    handle = dlopen("./libtime_conversion.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    *(void **)(&convert_to_hours) = dlsym(handle, "convert_to_hours");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading convert_to_hours: %s\n", error);
        dlclose(handle);
        return 1;
    }

    *(void **)(&convert_to_minutes) = dlsym(handle, "convert_to_minutes");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading convert_to_minutes: %s\n", error);
        dlclose(handle);
        return 1;
    }

    *(void **)(&convert_to_seconds) = dlsym(handle, "convert_to_seconds");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading convert_to_seconds: %s\n", error);
        dlclose(handle);
        return 1;
    }

    int total_seconds;
    int hours, minutes, seconds;

    printf("초를 입력하세요: ");
    scanf("%d", &total_seconds);

    convert_to_hours(total_seconds, &hours);
    convert_to_minutes(total_seconds, &minutes);
    convert_to_seconds(total_seconds, &seconds);

    printf("입력한 %d초는 %d시간 %d분 %d초입니다.\n", total_seconds, hours, minutes, seconds);

    dlclose(handle);

    return 0;
}

