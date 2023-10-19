#include <stdio.h>
#include <pthread.h>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int current_number = 1;
int max_number = 20; 

// Function to print even numbers
void *printEven(void *arg) {
    int *myid = (int *)arg;
    while (current_number <= max_number) {
        pthread_mutex_lock(&mutex);

        if (current_number % 2 == 0) {
            printf("Thread id :%d  Even: %d\n", myid,current_number);
            current_number++;
        }

        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

// Function to print odd numbers
void *printOdd(void *arg) {
    int *myid = (int *)arg;
    while (current_number <= max_number) {
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);

        if (current_number % 2 != 0) {
            printf("Thread id :%d  Odd: %d\n", *myid,current_number);
            current_number++;
        }

        // Release the mutex lock
        pthread_mutex_unlock(&mutex);

    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, printEven, NULL);
    pthread_create(&tid2, NULL, printOdd, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
