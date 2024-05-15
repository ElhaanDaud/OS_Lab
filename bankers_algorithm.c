/*Learning Objective: To understand how to implement Banker’s Algorithm in C.
Task: Write a C program to implement Banker’s Safety Algorithm for Deadlock Avoidance.

Note: Enter the number of Processes, number of Resources, Max Matrix, Allocation Matrix and Available Resources at runtime.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

// Function to check if the system is in a safe state
bool isSafe(int processes[], int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int need[][MAX_RESOURCES], int n, int m) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    // Initialize work with available resources
    for (int i = 0; i < m; i++)
        work[i] = available[i];

    while (count < n) {
        bool found = false;

        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[p][k];

                    safeSequence[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("The system is not in a safe state.\n");
            return false;
        }
    }

    printf("The system is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");

    return true;
}

int main() {
    int n, m;
    int processes[MAX_PROCESSES], available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES], allocation[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES];

    // Get the number of processes and resources from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Get the maximum matrix from the user
    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i;
        printf("For process P%d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Get the allocation matrix from the user
    printf("Enter the allocation resource matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("For process P%d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Get the available resources from the user
    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate the need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Check if the system is in a safe state
    isSafe(processes, available, max, allocation, need, n, m);

    return 0;
}
