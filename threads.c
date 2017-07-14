#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 10

void *my_multithreaded_func(void *arg) {
    int my_tid = *(int *)arg;
    int sleeptime = rand() % NUM_THREADS;

    sleep(sleeptime);
    fprintf(stdout, "Hello from %d\n", my_tid);

    pthread_exit(NULL);
}

int main(){
    pthread_t thr[NUM_THREADS];
    int tids[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        tids[i] = i;
        pthread_create(&thr[i], NULL, my_multithreaded_func, &tids[i]);
    }

    fprintf(stdout, "Waiting for threads.\n");
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thr[i], NULL);
    }
    fprintf(stdout, "Exiting.\n");
    return EXIT_SUCCESS;
}






