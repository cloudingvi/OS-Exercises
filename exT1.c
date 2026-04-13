#include <stdio.h>
#include <pthread.h>

void * print (void * args) {
    printf("hi from thread %u :>\n", pthread_self());
}

int main () {

    pthread_t thread;
    pthread_create(&thread, NULL, print, NULL);
    pthread_join(thread, NULL);
    printf("thread no more\n");

    return 0;
}