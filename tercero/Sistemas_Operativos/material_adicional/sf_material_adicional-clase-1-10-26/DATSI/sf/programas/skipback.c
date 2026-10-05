// ejemplo de uso de lseek visto en clase:
// 	recorre fichero hacia atrás saltándose un byte
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
	lseek(fd, -1, SEEK_END);
	while (read(fd, &car, 1)>0) {
	    write(1, &car, sizeof(car));
	    if ((lseek(fd, -3, SEEK_CUR)) < 0) break;
	}

	close(fd);
	return 0;
}
