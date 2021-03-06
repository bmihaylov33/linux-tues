#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	
	char buff[3];
	int i,j;
	int commas = 0;
	int sentences = 0;
	char previous_char = '.';

	if(argc > 1) {

		for(i = 1 ; i < argc; i++){
			
			int fp = open(argv[i], O_RDONLY);

			if(fp == -1) {
				perror("Open");
				return 1;
			}

			while(1) {
				int f = read(fp,&buff,1);

				if(f < 0) {
					perror("Read");
					return 1;
				}

				for (j = 0; j < f; j++) {
					
					if(buff[j] == ',') {
						commas++;
					} 
					else if(buff[j] == '.' && previous_char != '.') {
						sentences++;
					}
		            previous_char = buff[j];

					write(f,&buff,1);
				}

				if(f == 0) {
					break;
				}
			}

			int close_file = close(fp);
			
			if(close_file != 0){
				perror("Close");
			}

			printf("\nCommas: %d\nSentences: %d\n", commas, sentences);

			commas = 0;
			sentences = 0;
		}

	}	else {
			perror("No file to read");
	}
	
	return 0;
}