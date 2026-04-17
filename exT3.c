#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * function (void * args) {
    int *arr = (int *) args;
    int i = arr[0];
    int n = arr[1];
    printf("thread n. %d out of %d reporting for duty!\n", i, n);
    pthread_exit(NULL);
}
 
int main () {
    int numThreads;
    char * env = getenv("NUM_THREADS");
    if (env == NULL) {
        numThreads = 2;
        printf("no value found; defaulted to %d\n", numThreads);
    }
    else {
        numThreads = atoi(env);
        printf("found value is %d\n", numThreads);
    }

    printf("got here with n = %d\n", numThreads);

    for (int i = 0; i < numThreads; i++) {
        pthread_t thread;
        int args [2] = {i, numThreads};
        pthread_create(&thread, NULL, function, (void *) args);
        pthread_join(thread, NULL);
    }

    return 0;
}