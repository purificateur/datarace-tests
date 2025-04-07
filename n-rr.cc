#include <stdio.h>
#include <pthread.h>

int shared_var = 42; // initialized once, never written again

void* reader1(void* arg) {
    int local;
    for (int i = 0; i < 1000000; i++) {
        local = shared_var;
    }
    return NULL;
}

void* reader2(void* arg) {
    int local;
    for (int i = 0; i < 1000000; i++) {
        local = shared_var;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, reader1, NULL);
    pthread_create(&t2, NULL, reader2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
