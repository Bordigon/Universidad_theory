#include <unistd.h>    // Para read(), write(), lseek() y close()
#include <fcntl.h>     // Para open() y la bandera O_RDWR
#include <sys/stat.h>  // Para fstat() y la estructura struct stat
#include <stddef.h>    // Para el tipo de dato size_t

int main(int argc, char *argv[]) {
    char c1, c2; struct stat st;
    int fd = open(argv[1], O_RDWR);
    fstat(fd, &st);
    for (size_t i=0; i < st.st_size/2; i++) {
        read(fd, &c1, 1); // PUNTO1: lee el siguiente carácter de la primera mitad del fichero
        lseek(fd, -(i+1), SEEK_END);
        read(fd, &c2, 1); // PUNTO2: lee el carácter correspondiente de la segunda mitad del fichero
        lseek(fd, -1, SEEK_CUR);
        write(fd, &c1, 1); // PUNTO3: escribe el carácter de la primera mitad en el lugar correspondiente de la segunda
        lseek(fd, i, SEEK_SET);
        write(fd, &c2, 1); // PUNTO4: escribe el carácter de la segunda mitad en el lugar correspondiente de la primera
    }
    close(fd);
    return 0;
}