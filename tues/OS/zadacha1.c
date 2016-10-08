#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	char buff[3];
	int i;

	for(i = 1; i < argc ; i++) {
		
		int fp = open(argv[i], O_RDONLY);

		if(fp == 0) {
			printf("kurrrr\n");
		}

		while(1) {
			int f = read(fp,buff,1);
			write(STDOUT_FILENO,&buff,f);

			if(f == NULL) {
				break;
			}
		}
		printf("\n");
		close(fp);
	}

	return 0;
}