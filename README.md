# Linux System Resource Monitor and Manager

A C-based tool for Linux system administrators to monitor and manage system resources effectively. This project provides features like CPU and memory monitoring, process management, and system logging, all via an interactive command-line interface.

---

## Features
- **System Monitoring**:
  - Display real-time CPU and memory usage.
  - Monitor running processes with their details.

- **Process Management**:
  - List all running processes.
  - Search and kill processes by PID.

- **System Actions**:
  - Clear system caches (requires root privileges).
  - Log system statistics to a file for analysis.

- **Interactive Menu**:
  - Easy-to-use command-line menu for navigation.

---

## Project Structure
```plaintext
.
├── main.c         # Entry point of the program
├── monitor.c      # System monitoring functions (CPU, memory)
├── monitor.h      # Header file for monitor.c
├── process.c      # Process management functions
├── process.h      # Header file for process.c
├── logger.c       # Logging functionality
├── logger.h       # Header file for logger.c
```
## Installation and Compilation

### Prerequisites
- A Linux system.
- GCC compiler installed (e.g., `sudo apt install gcc` on Debian-based systems).

### Steps to Compile
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/sysmon.git
   cd sysmon
   ```

2. Compile the project using gcc:
   ```bash
   gcc main.c monitor.c process.c logger.c -o sysmon
   ```

3. Run the Program:
   ```bash
   ./sysmon
   ```
  



