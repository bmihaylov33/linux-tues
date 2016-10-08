#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char **argv) {
    
    struct stat s;
    int e = stat(".",&s);

    if (e != 0) {
        perror("stat: ");
    }    

    printf("%ld\n", s.st_size);


    return 0;
}