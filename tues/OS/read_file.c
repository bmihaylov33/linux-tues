#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	char array[3];
	char n[25];
	int count = 0;

	printf("Enter your file: ");
	gets(n);

	int fp = open(n, O_RDONLY);

	while(count < 10) {

		int f = read(fp,array,1);
			
			write(STDOUT_FILENO,&array,f);
		
			if(f == 0) {
				break;
			}
		} 
		close(fp);

	return 0;
}