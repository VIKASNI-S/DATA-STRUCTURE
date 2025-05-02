//Header file for Round_Robin

#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <iostream>
using namespace std;


class Process {
public:
    int time;
    Process* next;
    Process(int t);
};


void insertProcess(int time);
void executeProcess();
void displayQueue();

#endif


Process* tail = nullptr;
int timeSlice;

Process::Process(int t) : time(t), next(nullptr) {}

// Function to insert a process
void insertProcess(int time) {
    Process* newProcess = new Process(time);
    if (tail == nullptr) {
        newProcess->next = newProcess;
        tail = newProcess;
    } else {
        newProcess->next = tail->next;
        tail->next = newProcess;
        tail = newProcess;
    }
}

// Function to execute a process
void executeProcess() {
    if (tail == nullptr) {
        cout << "No processes in the queue." << endl;
        return;
    }

    Process* head = tail->next;
    cout << "Executing process with " << head->time << " time units" << endl;
    head->time -= timeSlice;

    if (head->time <= 0) {
        cout << "Process completed." << endl;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    } else {
        cout << "Process needs " << head->time << " more time units, re-adding to queue." << endl;
        tail = head;
    }
}

// Function to display the process queue
void displayQueue() {
    if (tail == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }
    Process* temp = tail->next;
    cout << "Process Queue: ";
    do {
        cout << "[" << temp->time << "] ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}
