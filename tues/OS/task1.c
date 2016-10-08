#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv) {
	
	char arr[3];
	int count = 0,i;
	int comma = 0;
	int sentence = 0;
	
	if(argc > 1) {

	for(i = 1; i < argc; i++) {

		int fp = open(argv[i], O_RDONLY);
		char previous_char = '.';

		while(1) {

			int j;
			int f = read(fp,arr,1);

			for(j = 0; j < f; j++) {

				if(arr[j] == '.' && previous_char != '.') { 
					++sentence;
				}

				else if (arr[j] == ',') {
					++comma;
				}

	            previous_char = arr[j];

				write(STDOUT_FILENO,&arr,f);
			}
				if(f == 0) {
					break;
				}
			}
			
			close(fp);

			printf("\n");

			printf("Commas: %d\n", comma);
			printf("Sentences: %d\n", sentence);

			comma = 0;
			sentence = 0;
		}

	} else {
    		fprintf(stderr,"cannot open '%s' for reading \n", argv[i]);
			}

	return 0;
}