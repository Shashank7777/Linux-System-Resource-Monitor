#include <stdio.h>
#include <time.h>
#include "logger.h"

void log_system_stats(const char *message) {
    FILE *file = fopen("system_log.txt", "a");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(file, "%s: %s\n", ctime(&now), message);

    fclose(file);
}
