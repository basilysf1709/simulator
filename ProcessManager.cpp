#include "ProcessManager.h"
#include <iostream>

// Constructor implementation
Process::Process(int id, int prio) : pid(id), state(ProcessState::NEW), cpuTime(0), priority(prio) {}

// Getters implementation
int Process::getPid() const { return pid; }
ProcessState Process::getState() const { return state; }
int Process::getCpuTime() const { return cpuTime; }
int Process::getPriority() const { return priority; }

// Setters implementation
void Process::setState(ProcessState newState) { state = newState; }
void Process::setCpuTime(int time) { cpuTime = time; }
void Process::setPriority(int prio) { priority = prio; }

// Process methods implementation
void Process::start() {
    if (state == ProcessState::NEW || state == ProcessState::READY) {
        state = ProcessState::RUNNING;
        std::cout << "Process " << pid << " started." << std::endl;
    }
}

void Process::stop() {
    if (state == ProcessState::RUNNING) {
        state = ProcessState::WAITING;
        std::cout << "Process " << pid << " stopped." << std::endl;
    }
}

void Process::terminate() {
    state = ProcessState::TERMINATED;
    std::cout << "Process " << pid << " terminated." << std::endl;
}

void Process::update(int cpuCycle) {
    if (state == ProcessState::RUNNING) {
        cpuTime += cpuCycle;
        std::cout << "Process " << pid << " ran for " << cpuCycle << " cycles." << std::endl;
    }
}
