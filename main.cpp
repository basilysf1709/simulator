#include "ProcessManager.h"

int main() {
    Process proc1(1, 5); // Create a process with PID 1 and priority 5
    proc1.start();
    proc1.update(10); // Simulate that the process has run for 10 ticks
    proc1.stop();
    proc1.terminate();

    return 0;
}
