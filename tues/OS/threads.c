#include <pthread.h>
#include <stdio.h>

pthread_mutex_t m1;
pthread_mutex_t m2;

int global_counter1 = 0;
int global_counter2 = 0;

void* asdf(void* a) {

    int i = 0;
    for (i = 0; i < 80000; i++) {
        pthread_mutex_lock(&m1);
        global_counter1++;
        pthread_mutex_unlock(&m1);
    }
    for (i = 0; i < 80000; i++) {
        pthread_mutex_lock(&m2);
        global_counter2++;
        pthread_mutex_unlock(&m2);
    }
    return NULL;
}

void* asdf2(void* a) {

    int i = 0;
    for (i = 0; i < 80000; i++) {
        pthread_mutex_lock(&m1);
        global_counter1++;
        pthread_mutex_unlock(&m1);
    }
    for (i = 0; i < 80000; i++) {
        pthread_mutex_lock(&m2);
        global_counter2++;
        pthread_mutex_unlock(&m2);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&m1, NULL);
    pthread_mutex_init(&m2, NULL);

    pthread_t thread;
    pthread_create(&thread, NULL, asdf, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, asdf2, NULL);


    printf("going to wait for the other thread\n");
    pthread_join(thread, NULL);
    pthread_join(thread2, NULL);
    printf("other has finished!\n");

    printf("%d\n", global_counter1);
    printf("%d\n", global_counter2);

    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
    return 0;
}