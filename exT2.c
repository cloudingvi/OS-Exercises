#include <stdio.h>
#include <pthread.h>

void * function(void * i) {
    int result = (int) i * (int) i;
    printf("me (thread %d) got %d\n", i, result);
    pthread_exit((void *) result);
}

int main (int argc, char * argv[]) {
    int n = 4;

    for (int i = 0; i < n; i++) {
        void * retval;
        pthread_t thread;
        pthread_create(&thread, NULL, function, (void *)i);
        pthread_join(thread, &retval);
        printf("thread %d returned %u\n", i, (int *) retval);
    }

    return 0;
}