#include <stdio.h>
#include <pthread.h>

int shared_var1 = 0;
int shared_var2 = 0;

void* writer1(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_var1 = 1;
    }
    return NULL;
}

void* writer2(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_var2 = 1;
    }
    return NULL;
}

void* reader(void* arg) {
    int local_var1, local_var2;
    for (int i = 0; i < 100000; i++) {
        local_var1 = shared_var1; // Potential data race
        local_var2 = shared_var2; // Potential data race
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3, thread4, thread5, reader_thread;
    pthread_create(&thread1, NULL, writer1, NULL);
    pthread_create(&thread2, NULL, writer1, NULL);
    pthread_create(&thread3, NULL, writer2, NULL);
    pthread_create(&thread4, NULL, writer2, NULL);
    pthread_create(&thread5, NULL, writer2, NULL);
    pthread_create(&reader_thread, NULL, reader, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(reader_thread, NULL);
    return 0;
}
