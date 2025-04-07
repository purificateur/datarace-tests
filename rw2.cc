#include <stdio.h>
#include <pthread.h>

int shared_var = 0;

void* writer(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_var = 1;
    }
    return NULL;
}

void* reader(void* arg) {
    int local_var;
    for (int i = 0; i < 100000; i++) {
        local_var = shared_var; // Data race occurs here
    }
    return NULL;
}

int main() {
    pthread_t writer_thread, reader_thread;
    pthread_create(&writer_thread, NULL, writer, NULL);
    pthread_create(&reader_thread, NULL, reader, NULL);
    pthread_join(writer_thread, NULL);
    pthread_join(reader_thread, NULL);
    return 0;
}
