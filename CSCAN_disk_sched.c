/*Learning Objective: To understand how to implement C-SCAN Disk Scheduling Algorithm. 
Task: Write a C program to implement C-SCAN Disk Scheduling Algorithm with initial head position at 53 and disk size as 200 for the below sectors: 
98, 183, 37, 122, 14, 124, 65, 67

Expected Output: the total head movements and the sector sequence.

Note: Enter the number of sectors, the sectors and the initial head position at runtime.*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for sorting)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to implement C-SCAN Disk Scheduling Algorithm
void cscanDiskScheduling(int requests[], int num_requests, int initial_head, int disk_size) {
    int total_head_movements = 0;
    int current_head = initial_head;
    int index;

    // Sort the requests
    qsort(requests, num_requests, sizeof(int), compare);

    // Find the index where the head should start scanning
    for (index = 0; index < num_requests; index++) {
        if (requests[index] > current_head) {
            break;
        }
    }

    printf("Sector sequence: ");

    // Move towards the end of the disk
    for (int i = index; i < num_requests; i++) {
        printf("%d ", requests[i]);
        total_head_movements += abs(requests[i] - current_head);
        current_head = requests[i];
    }

    // Move to the end of the disk
    total_head_movements += abs(disk_size - 1 - current_head);
    current_head = disk_size - 1;

    // Move to the beginning of the disk
    total_head_movements += disk_size - 1;
    current_head = 0;

    // Move towards the initial request position
    for (int i = 0; i < index; i++) {
        printf("%d ", requests[i]);
        total_head_movements += abs(requests[i] - current_head);
        current_head = requests[i];
    }

    printf("\nTotal head movements: %d\n", total_head_movements);
}

int main() {
    int num_requests;
    int initial_head, disk_size;

    // Get the number of requests from the user
    printf("Enter the number of sectors: ");
    scanf("%d", &num_requests);

    int requests[num_requests];

    // Get the sector requests from the user
    printf("Enter the sectors:\n");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    // Get the initial head position from the user
    printf("Enter the initial head position: ");
    scanf("%d", &initial_head);

    // Get the disk size from the user
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    cscanDiskScheduling(requests, num_requests, initial_head, disk_size);

    return 0;
}
