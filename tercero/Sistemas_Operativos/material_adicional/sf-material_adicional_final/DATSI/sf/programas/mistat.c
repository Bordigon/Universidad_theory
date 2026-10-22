#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat sb;
    if (argc != 2) {
        fprintf(stderr, "Uso: %s fichero\n", argv[0]);
        return 1;
    }
    if (lstat(argv[1], &sb) == -1) {
        perror("lstat");
        return 1;
    }
    printf("tipo de fichero y permisos: %o\n\ttipo: ", sb.st_mode);
    if (S_ISBLK(sb.st_mode)) printf("dispositivo de bloques\n");
    else if (S_ISCHR(sb.st_mode)) printf("dispositivo de carácteres\n");
    else if (S_ISDIR(sb.st_mode)) printf("directorio\n");
    else if (S_ISFIFO(sb.st_mode)) printf("FIFO/pipe\n");
    else if (S_ISLNK(sb.st_mode)) printf("enlace simbólico\n");
    else if (S_ISREG(sb.st_mode)) printf("fichero regular\n");
    else if (S_ISSOCK(sb.st_mode)) printf("socket\n");
    else printf("tipo de dispositivo desconocido\n");

    printf("\tpermisos: 0%o\t", sb.st_mode & ~S_IFMT);
    printf("%c", (sb.st_mode & S_ISUID)? 's':'-'); 
    printf("%c", (sb.st_mode & S_ISGID)? 's':'-'); 
    printf("%c", (sb.st_mode & S_ISVTX)? 't':'-'); 
    printf("%c", (sb.st_mode & S_IRUSR)? 'r':'-'); 
    printf("%c", (sb.st_mode & S_IWUSR)? 'w':'-'); 
    printf("%c", (sb.st_mode & S_IXUSR)? 'x':'-'); 
    printf("%c", (sb.st_mode & S_IRGRP)? 'r':'-'); 
    printf("%c", (sb.st_mode & S_IWGRP)? 'w':'-'); 
    printf("%c", (sb.st_mode & S_IXGRP)? 'x':'-'); 
    printf("%c", (sb.st_mode & S_IROTH)? 'r':'-'); 
    printf("%c", (sb.st_mode & S_IWOTH)? 'w':'-'); 
    printf("%c", (sb.st_mode & S_IXOTH)? 'x':'-'); 

    printf("\ndispositivo:  [%x,%x]\n", major(sb.st_dev), minor(sb.st_dev));
    printf("número de i-nodo: %lu\n", sb.st_ino);

    printf("número de enlaces : %lu\n", sb.st_nlink);
    printf("dueño: UID=%u GID=%u\n", sb.st_uid, sb.st_gid);
    printf("tamaño recomendado para operaciones de E/S: %ld bytes\n", sb.st_blksize);
    printf("tamaño del fichero: %ld bytes\n", sb.st_size);
    printf("bloques asignados al fichero (en Linux usa como unidad bloques de 512 bytes): %ld\n", sb.st_blocks);

    printf("fecha de última modificación del i-nodo : %s", ctime(&sb.st_ctime));
    printf("fecha de último acceso: %s", ctime(&sb.st_atime));
    printf("fecha de última modificación de datos: %s", ctime(&sb.st_mtime));

    return 0;
}

