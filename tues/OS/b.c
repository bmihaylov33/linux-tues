#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char** argv) {

	int i,p;
	struct stat s;

	if(argc > 1) {

		for(i = 1; i < argc; i++) {
			
			DIR* d = opendir(argv[i]);

			if(d == NULL) {
				perror("Open");
				return 1;
			}

			p = stat(argv[i],&s);

			while(1) {

				struct dirent* e = readdir(d);

				if(e == NULL) {
					break;
				}

				printf("%ld %s\n",s.st_blocks, e->d_name);
			}
			closedir(d);
		}
	
	} else {
		perror("No dir to open.\n");
		return 1;
	}

	return 0;
}