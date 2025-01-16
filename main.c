#include <stdio.h>
#include <stdlib.h>
#include "monitor.h"
#include "process.h"
#include "logger.h"

void display_menu() {
    printf("\nLinux System Resource Monitor and Manager\n");
    printf("-----------------------------------------\n");
    printf("1. Display Memory Usage\n");
    printf("2. Display CPU Usage\n");
    printf("3. List Running Processes\n");
    printf("4. Kill a Process\n");
    printf("5. Log System Stats\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, pid;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_memory_usage();
                break;
            case 2:
                display_cpu_usage();
                break;
            case 3:
                list_processes();
                break;
            case 4:
                printf("Enter PID to kill: ");
                scanf("%d", &pid);
                kill_process(pid);
                break;
            case 5:
                log_system_stats("System statistics logged.");
                printf("System stats logged.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
