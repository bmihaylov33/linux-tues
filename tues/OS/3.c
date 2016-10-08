#include <pthread.h>
#include <stdio.h>

void* print(void* thread){

	int td,i;

	td = (int)thread;

	for(i = 0; i < 20; i++){

		printf("Hello from thread %d\n", td);
	}

		pthread_exit(NULL);
}

int main() {

	int a = 1;
	int b = 2;
	int *pa = &a;
	int *pb = &b;

	pthread_t thread1;
	pthread_t thread2;

	pthread_create(thread1, NULL, print, a);
	pthread_create(thread2, NULL, print, b);

	return 0;
}