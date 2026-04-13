#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * function (int i) {
    printf("thread n. %d reporting for duty!\n", i);
    return;
}

int main () {
    int numThreads;
    char * env = getenv("NUM_THREADS");
    if (env == NULL) {
        numThreads = 2;
        printf("no value found; defaulted to %d\n", numThreads);
    }
    else {
        int n = atoi(numThreads);
        printf("found value is %d\n", n);
    }

    printf("got here with n = %d\n", numThreads);

    for (int i = 0; i < numThreads; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, function, i);
        pthread_join(&thread, NULL);
    }

    return 0;
}