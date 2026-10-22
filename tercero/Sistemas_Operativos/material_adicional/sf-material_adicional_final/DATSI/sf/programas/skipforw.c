// ejemplo de uso de lseek visto en clase:
// 	recorre fichero hacia adelante saltándose un byte
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(int  argc, char **argv) {
	int fd;
	char car;

	if (argc!=2)  {
		fprintf (stderr, "Uso: %s archivo\n", argv[0]);
		return 1;
	}

	/* Abre el archivo */
	if ((fd=open(argv[1], O_RDWR))<0) {
		perror("No puede abrirse el archivo");
		return 1;
	}
	while (read(fd, &car, 1)>0) {
	    lseek(fd, 1, SEEK_CUR);
	    write(1, &car, sizeof(car));
	}

	close(fd);
	return 0;
}
