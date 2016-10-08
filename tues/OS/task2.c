#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char **argv) {
    
    struct stat s;
    int i,e;

    if(argc > 1) {

    for(i = 1; i < argc; i++) {
    	DIR* d = opendir(argv[i]);

    	if(d == NULL){
    		perror(".");
    		return 1;
    	}
    	
    	e = stat(argv[i],&s);

    	while(1) {
    		errno = 0;
    		struct dirent* p = readdir(d);

    		if (p == NULL) {
	            if (errno != 0) {
	                perror("readdir");
	                break;
	            } else {
	                break;
	            }
        	}
        
        printf("%ld %s\n", s.st_blocks, p->d_name);
       	//printf("%ld %s\n", s.st_blocks, argv[i]);

    	} 
    	closedir(d);

    	 if (e != 0) {
    	    perror("stat: ");
	    }   
   	}
}
   	else {
   		printf("cannot opendir\n");
   	}


    return 0;
}