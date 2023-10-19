#include <stdio.h>
#include <pthread.h>



int current_number = 1;
int max_number = 20;

// Function to print even numbers
void *printEven(void *arg) {
    int *myid = (int *)arg;
    while (current_number <= max_number) {
        

        if (current_number % 2 == 0) {
            printf("ThreadId: %d   Even: %d\n", *myid, current_number);
            current_number++;
        }
    }
    pthread_exit(NULL);
    return NULL;
}

// Function to print odd numbers
void *printOdd(void *arg) {
    int *myid = (int *)arg; // Cast to int
    while (current_number <= max_number) {
        

        if (current_number % 2 != 0) {
            printf("ThreadId: %d   Odd: %d\n", *myid, current_number);
            current_number++;
        }
    }
    pthread_exit(NULL);
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    int id1 = 1;
    int id2 = 2;

    pthread_create(&tid1, NULL, printEven, &id1); // Pass thread ID as an argument
    pthread_create(&tid2, NULL, printOdd, &id2);  // Pass thread ID as an argument

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
