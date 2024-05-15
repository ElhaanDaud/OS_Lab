/*Learning Objective: To understand how to implement Round Robin CPU Scheduling Algorithm.
Task: Write a C program to simulate Round Robin CPU scheduling algorithm with Time Quantum = 3 to find waiting time for the below problem:

Process    Burst Time
P0         24
P1         3
P2         3

Note: Make the user enter the number of processes, burst time for each process and time quantum at runtime.*/

#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int burst_time[], int waiting_time[], int time_quantum) {
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++)
        remaining_burst_time[i] = burst_time[i];

    int current_time = 0; // current time

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0; // there is a pending process

                if (remaining_burst_time[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                } else {
                    current_time += remaining_burst_time[i];
                    waiting_time[i] = current_time - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int burst_time[], int time_quantum) {
    int waiting_time[n];
    int total_waiting_time = 0;

    findWaitingTime(processes, n, burst_time, waiting_time, time_quantum);

    printf("Processes   Burst Time   Waiting Time\n");

    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        printf("P%d          %d           %d\n", processes[i], burst_time[i], waiting_time[i]);
    }

    float average_waiting_time = (float)total_waiting_time / (float)n;
    printf("Average waiting time = %.2f\n", average_waiting_time);
}

int main() {
    int n, time_quantum;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];

    // Get the burst time for each process from the user
    for (int i = 0; i < n; i++) {
        processes[i] = i; // process ID
        printf("Enter burst time for process P%d: ", i);
        scanf("%d", &burst_time[i]);
    }

    // Get the time quantum from the user
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    findAverageTime(processes, n, burst_time, time_quantum);

    return 0;
}
