#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t rw_mutex, mutex;
int read_count = 0;
int data = 0;

void *writer(void *arg) {
    sem_wait(&rw_mutex);
    data++;  // Escrita no recurso compartilhado
    printf("Escritor %ld alterou o dado para %d\n", (long)arg, data);
    sem_post(&rw_mutex);
    return NULL;
}

void *reader(void *arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&rw_mutex);  // Primeiro leitor bloqueia os escritores
    sem_post(&mutex);

    printf("Leitor %ld leu o dado %d\n", (long)arg, data);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&rw_mutex);  // Último leitor libera os escritores
    sem_post(&mutex);
    return NULL;
}

int main() {
    pthread_t readers[5], writers[5];
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    for (long i = 0; i < 5; i++) {
        pthread_create(&writers[i], NULL, writer, (void *)i);
        pthread_create(&readers[i], NULL, reader, (void *)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    return 0;
}

