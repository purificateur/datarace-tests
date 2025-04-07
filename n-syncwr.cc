#include <stdio.h>
#include <pthread.h>

int shared_var = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* writer(void* arg) {
    pthread_mutex_lock(&lock);
    shared_var = 99;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* reader(void* arg) {
    int val;
    pthread_mutex_lock(&lock);
    val = shared_var;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, writer, NULL);
    pthread_create(&t2, NULL, reader, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
