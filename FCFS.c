/*Learning Objective: To understand how to code a simple CPU Scheduling Algorithm.
Task: Write a C program to simulate FCFS(First Come First Serve) CPU scheduling algorithm to find waiting time for the below problem:

| Process | Burst Time |
| --- | --- |
| P0 | 24 |
| P1 | 3 |
| P2 | 3 |


Note: Make the user enter the number of processes and burst time for each process at runtime.*/

#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int burst_time[], int waiting_time[]) {
    waiting_time[0] = 0; // waiting time for first process is 0

    // calculating waiting time for each process
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
}

// Function to find average time
void findAverageTime(int processes[], int n, int burst_time[]) {
    int waiting_time[n];
    int total_waiting_time = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, burst_time, waiting_time);

    // Display processes along with burst time and waiting time
    printf("Processes   Burst Time   Waiting Time\n");

    // Calculate total waiting time
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        printf("P%d          %d           %d\n", processes[i], burst_time[i], waiting_time[i]);
    }

    // Calculate average waiting time
    float average_waiting_time = (float)total_waiting_time / (float)n;
    printf("Average waiting time = %.2f\n", average_waiting_time);
}

int main() {
    int n;

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

    findAverageTime(processes, n, burst_time);

    return 0;
}
