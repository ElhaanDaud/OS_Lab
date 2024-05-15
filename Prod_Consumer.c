/*Learning Objective: To understand how to implement the Producer Consumer Problem. 
Task: Write a C program to implement Producer Consumer Problem using Semaphores.

Hint: https://www.javatpoint.com/producer-consumer-problem-in-os*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10

// Buffer and associated variables
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// Semaphores
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

// Function for the producer thread
void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 100; // Produce a random item

        sem_wait(&empty); // Wait if buffer is full
        pthread_mutex_lock(&mutex); // Lock the buffer

        buffer[in] = item; // Add the item to the buffer
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&full); // Signal that the buffer is not empty

        sleep(1); // Simulate time taken to produce an item
    }
}

// Function for the consumer thread
void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full); // Wait if buffer is empty
        pthread_mutex_lock(&mutex); // Lock the buffer

        item = buffer[out]; // Remove the item from the buffer
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&empty); // Signal that the buffer is not full

        sleep(1); // Simulate time taken to consume an item
    }
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize the semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create the producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for the threads to finish (they won't, in this infinite loop example)
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Destroy the semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
