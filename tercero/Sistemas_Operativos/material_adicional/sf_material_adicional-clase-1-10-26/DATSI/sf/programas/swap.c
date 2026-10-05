// ejemplo de uso de lseek visto en clase:
// 	invierte el contenido de un fichero
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int fd;
    struct stat st;
    char car1, car2;

    if (argc!=2)  {
        fprintf (stderr, "Uso: %s archivo\n", argv[0]);
        return 1;
    }
    /* Abre el archivo */
    if ((fd=open(argv[1], O_RDWR))<0) {
        perror("No puede abrirse el archivo");
        return 1;
    }
    fstat(fd, &st);

    for (int i=0; i<st.st_size/2; i++) {
        read(fd, &car1, 1);
        lseek(fd, -i-1, SEEK_END);
        read(fd, &car2, 1);
        lseek(fd, -1, SEEK_CUR);
        write(fd, &car1, 1);
        lseek(fd, i, SEEK_SET);
        write(fd, &car2, 1);
    }
    close(fd);
    return(0);
}
