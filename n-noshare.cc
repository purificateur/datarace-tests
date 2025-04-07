#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int local_var = 0;
    for (int i = 0; i < 1000000; i++) {
        local_var += i;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
