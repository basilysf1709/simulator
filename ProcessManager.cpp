#include <iostream>
#include <string>

enum class ProcessState {
    NEW, RUNNING, WAITING, READY, TERMINATED
};

class Process {
private:
    int pid;
    ProcessState state;
    int cpuTime; // Simulated CPU time in "ticks"
    int priority; // Lower numbers indicate higher priority

public:
    Process(int id, int prio = 0) : pid(id), priority(prio), state(ProcessState::NEW), cpuTime(0) {}

    // Getters
    int getPid() const { return pid; }
    ProcessState getState() const { return state; }
    int getCpuTime() const { return cpuTime; }
    int getPriority() const { return priority; }

    // Setters
    void setState(ProcessState newState) { state = newState; }
    void setCpuTime(int time) { cpuTime = time; }
    void setPriority(int prio) { priority = prio; }

    // Basic process controls
    void start() {
        if (state == ProcessState::NEW || state == ProcessState::READY) {
            state = ProcessState::RUNNING;
            std::cout << "Process " << pid << " started." << std::endl;
        }
    }

    void stop() {
        if (state == ProcessState::RUNNING) {
            state = ProcessState::WAITING;
            std::cout << "Process " << pid << " stopped." << std::endl;
        }
    }

    void terminate() {
        state = ProcessState::TERMINATED;
        std::cout << "Process " << pid << " terminated." << std::endl;
    }

    void update(int cpuCycle) {
        if (state == ProcessState::RUNNING) {
            cpuTime += cpuCycle;
            std::cout << "Process " << pid << " ran for " << cpuCycle << " cycles." << std::endl;
        }
    }
};

int main() {
    Process proc1(1, 5); // Create a process with PID 1 and priority 5
    proc1.start();
    proc1.update(10); // Simulate that the process has run for 10 ticks
    proc1.stop();
    proc1.terminate();

    return 0;
}
