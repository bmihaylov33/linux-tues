#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

int a = 0;
pthread_mutex_t m;

void* work(void *arg) {
    int i;

    for(i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&m);
        a++;
        pthread_mutex_unlock(&m);

        pthread_mutex_lock(&m);
        if(a == 100000) {
            printf("a is big number\n");
        }    
        pthread_mutex_unlock(&m);

    } return NULL;
}

int main() {
    pthread_mutex_init(&m, NULL);
    pthread_t t[2];
    pthread_create(&t[0], NULL, work, NULL);        
    pthread_create(&t[1], NULL, work, NULL);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    printf("%d\n", a);    

    return 0;
}