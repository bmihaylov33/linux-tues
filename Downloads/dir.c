#include <stdio.h>
#include <dirent.h>

int main() {
    DIR* d = opendir(".");

    if(d == NULL) {
        perror("ERROR in opendir :");   
    }

    struct dirent *p = readdir(d);

    while(p != NULL) {
        if(p->d_type == DT_DIR) {
            printf("d ");
        } else {
            if (p->d_type == DT_REG) { 
                printf("f ");
            } 
        } else { 
                printf("? ");
        }
    }
        
    printf("%s\n", p->d_name);
    p = readdir(d);

    closedir(d);

    return 0;
}