#include <stdio.h>
#include <pthread.h>

int shared_var = 0;
int num_threads = 50;

void* write(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_var = shared_var + 1;
    }
    return NULL;
}

int main() {
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, write, NULL);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Final value of shared_var: %d\n", shared_var);
    return 0;
}
