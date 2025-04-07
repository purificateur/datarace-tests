#include <stdio.h>
#include <pthread.h>

int shared_read_only = 100;
int thread_local_1 = 0;
int thread_local_2 = 0;

void* thread1(void* arg) {
    thread_local_1 = shared_read_only + 1;
    return NULL;
}

void* thread2(void* arg) {
    thread_local_2 = shared_read_only + 2;
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
