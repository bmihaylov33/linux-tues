#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *Thread(void *thread_id){
	int tid, err;
	long i;	
	
	for(i = 0; i < 100000000; i++) {
		double a = cos(i) * cos(i) + sin(i) * sin(i);
		if (a > 1.0005 || a < 0.9995) {
			err = 1;
	
			pthread_exit (NULL);
			
		}
	}
}

int main(int argc, char *argv[]) {
	pthread_t threads [NUM_THREADS];
   	int err,t;

	for(t = 0; t < NUM_THREADS; t++) {	
		err = pthread_create(&(threads[t]), NULL, Thread, NULL);
		if(err) {
			printf("ERROR; pthread_create() return %d\n",err);
				exit(-1);
	    	}
	}	


	for (t = 0; t < NUM_THREADS; t++) {
		void *status;
		int err = pthread_join(threads[t],(void **)&status);
	
		if(err) {
			printf("ERROR; pthread_join()return %d\n",err);
				exit(-1);
		}

	printf("Thread %d: Result = %d\n",t , err);
	//pthread_exit (NULL);
	}
	
	return 0;
}
