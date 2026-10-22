#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]){/* directorio se pasa como argumento */
    DIR *dirp;
    struct dirent *dp;
    
    if (argc!=2) {
        fprintf(stderr, "Uso: %s directorio\n", argv[0]); return 1;
    }
    /* abre el directorio pasado como argumento */
    if ((dirp = opendir(argv[1])) == NULL)
        perror("error en opendir");
    else {
getchar();
        /* lee entrada a entrada */
        while ((dp = readdir(dirp)) != NULL)
            printf("%ld %s\n", dp->d_ino, dp->d_name);
        closedir(dirp);  
    }
    return 0;
}
