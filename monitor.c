#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monitor.h"

// Function to read and display memory usage
void display_memory_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemTotal", 8) == 0 || strncmp(line, "MemFree", 7) == 0 || strncmp(line, "Buffers", 7) == 0) {
            printf("%s", line);
        }
    }

    fclose(file);
}

// Function to display CPU usage
void display_cpu_usage() {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        return;
    }

    char line[256];
    if (fgets(line, sizeof(line), file)) {
        printf("CPU Usage: %s", line);
    }

    fclose(file);
}

