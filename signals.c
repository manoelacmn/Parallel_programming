#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("Recebido sinal %d\n", sig);
}

void *task(void *arg) {
    signal(SIGUSR1, signal_handler);
    printf("Thread %ld aguardando sinal...\n", (long)arg);
    pause();  // Espera por um sinal
    printf("Thread %ld recebeu o sinal e continua...\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, task, (void *)1);

    sleep(1);  // Simula algum processamento antes de enviar o sinal
    pthread_kill(thread, SIGUSR1);  // Envia um sinal SIGUSR1 para a thread

    pthread_join(thread, NULL);
    return 0;
}

