#include <stdio.h>
#include <pthread.h>

int shared_var = 0;

void* writer(void* arg) {
    shared_var = 123;
    return NULL;
}

void* reader(void* arg) {
    printf("Read value: %d\n", shared_var);
    return NULL;
}

int main() {
    pthread_t writer_thread, reader_thread;

    pthread_create(&writer_thread, NULL, writer, NULL);
    pthread_join(writer_thread, NULL);  // ensures write happens-before read

    pthread_create(&reader_thread, NULL, reader, NULL);
    pthread_join(reader_thread, NULL);

    return 0;
}
