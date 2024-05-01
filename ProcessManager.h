#ifndef PROCESS_H
#define PROCESS_H

// Enum class for process states
enum class ProcessState {
    NEW, RUNNING, WAITING, READY, TERMINATED
};

// Process class definition
class Process {
private:
    int pid;            // Process ID
    ProcessState state; // Current state of the process
    int cpuTime;        // CPU time used by the process in ticks
    int priority;       // Priority of the process

public:
    Process(int id, int prio = 0); // Constructor

    // Getters
    int getPid() const;
    ProcessState getState() const;
    int getCpuTime() const;
    int getPriority() const;

    // Setters
    void setState(ProcessState newState);
    void setCpuTime(int time);
    void setPriority(int prio);

    // Process methods
    void start();
    void stop();
    void terminate();
    void update(int cpuCycle);
};

#endif // PROCESS_H
