#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h> // Added for isdigit
#include <signal.h>
#include "process.h"

// Function to list all processes
void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (!dp) {
        perror("Failed to open /proc");
        return;
    }

    printf("PID\tName\n");
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            char path[256];
            char cmdline[256] = {0}; // Initialize the buffer to avoid garbage data
            snprintf(path, sizeof(path), "/proc/%s/cmdline", entry->d_name);

            FILE *file = fopen(path, "r");
            if (file) {
                if (fgets(cmdline, sizeof(cmdline) - 1, file)) { // Safeguard against buffer overflow
                    printf("%s\t%s\n", entry->d_name, cmdline);
                }
                fclose(file);
            }
        }
    }
    closedir(dp);
}
