/*Learning Objective: To understand how to implement Optimal Page Replacement Algorithm.

Task: Write a C program to implement Optimal Page Replacement Algorithm for the below reference string:
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

// Function to find the index of the page to be replaced using the Optimal algorithm
int findPageToReplace(int frames[], int num_frames, int reference_string[], int num_pages, int current_index) {
    int farthest = current_index;
    int replace_index = -1;

    for (int i = 0; i < num_frames; i++) {
        int j;
        for (j = current_index; j < num_pages; j++) {
            if (frames[i] == reference_string[j]) {
                if (j > farthest) {
                    farthest = j;
                    replace_index = i;
                }
                break;
            }
        }
        // If the page is not found in the future reference string, return this index
        if (j == num_pages) {
            return i;
        }
    }

    return (replace_index == -1) ? 0 : replace_index;
}

// Function to implement Optimal Page Replacement Algorithm
int optimalPageReplacement(int reference_string[], int num_pages, int num_frames) {
    int frames[num_frames];
    int page_faults = 0;

    // Initialize all frames to -1 (indicating empty)
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        if (!isPageInFrame(reference_string[i], frames, num_frames)) {
            // Page fault occurs
            if (i < num_frames) {
                frames[i] = reference_string[i];
            } else {
                int replace_index = findPageToReplace(frames, num_frames, reference_string, num_pages, i);
                frames[replace_index] = reference_string[i];
            }
            page_faults++;
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

    int page_faults = optimalPageReplacement(reference_string, num_pages, num_frames);

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}


