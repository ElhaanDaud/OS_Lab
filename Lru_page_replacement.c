/*Learning Objective: To understand how to implement LRU Page Replacement Algorithm.

Task: Write a C program to implement LRU Page Replacement Algorithm for the below reference string:
7, 0 ,1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1

Expected Output: Print the number of page faults.



Note: Enter the reference string and the number of frames at runtime.*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if a page is in the frame
bool isPageInFrame(int page, int frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the least recently used page index
int findLRU(int time[], int num_frames) {
    int min = time[0], pos = 0;
    for (int i = 1; i < num_frames; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

// Function to implement LRU Page Replacement Algorithm
int lruPageReplacement(int reference_string[], int num_pages, int num_frames) {
    int frames[num_frames];
    int time[num_frames];
    int page_faults = 0;
    int counter = 0;

    // Initialize all frames to -1 (indicating empty)
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < num_pages; i++) {
        if (!isPageInFrame(reference_string[i], frames, num_frames)) {
            int lru_index = findLRU(time, num_frames);
            frames[lru_index] = reference_string[i];
            time[lru_index] = counter++;
            page_faults++;
        } else {
            // Update time for the page
            for (int j = 0; j < num_frames; j++) {
                if (frames[j] == reference_string[i]) {
                    time[j] = counter++;
                    break;
                }
            }
        }
    }

    return page_faults;
}

int main() {
    int num_pages, num_frames;

    // Get the number of pages in the reference string from the user
    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &num_pages);

    int reference_string[num_pages];

    // Get the reference string from the user
    printf("Enter the reference string:\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &reference_string[i]);
    }

    // Get the number of frames from the user
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    int page_faults = lruPageReplacement(reference_string, num_pages, num_frames);

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}

// Input: 7, 0 ,1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1
