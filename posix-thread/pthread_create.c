#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *ptr);

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    iret1 = pthread_create(&thread1, NULL, print_message, (void*)message1);
    iret2 = pthread_create(&thread2, NULL, print_message, (void*)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread1 returns: %d\n", iret1);
    printf("Thread2 returns: %d\n", iret2);

    return 0;
}

void *print_message(void *ptr) {
    char *message;
    message = (char*)ptr;
    printf("%s\n", message);
}
