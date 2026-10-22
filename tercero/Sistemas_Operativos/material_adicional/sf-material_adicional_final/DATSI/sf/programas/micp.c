#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv) { 
	int fd_ent, fd_sal, n_read; 
        if (argc!=3) {
                fprintf(stderr, "Uso: %s fichero_origen fichero_destino\n", argv[0]);
                return 1; 
        }
	//Abre fichero origen o entrada 
	fd_ent = open(argv[1], O_RDONLY); 
	if (fd_ent < 0) {  //error apertura
	   perror("open"); //transforma errno en un mensaje de error
	   exit(1); 
	} 
	//Crea fichero de destino o salida 
	fd_sal = creat(argv[2], 0666); 
	if (fd_sal < 0) { //error apertura 
	   close(fd_ent); 
	   perror("creat"); 
	   exit(1); 
	} 
	//averigua el tamaño óptimo para acceder al fichero
	int err;
	struct stat st;
	err = fstat(fd_ent, &st); 
	if (err < 0) {  //error en stat
	   perror("stat"); //transforma errno en un mensaje de error
	   exit(1); 
	} 
	/* bucle de lectura del fichero de entrada */
	char buffer[st.st_blksize]; 
	while ((n_read = read(fd_ent, buffer, sizeof(buffer))) > 0) {
	   /* escribir el buffer al fichero de salida */
	   if (write(fd_sal, buffer, n_read) < n_read) {//error escritura
	      perror("write");
	      close(fd_ent);
	      close(fd_sal);
	      exit(1);
	   }
	}
	close(fd_ent);
	close(fd_sal);
	
	if (n_read < 0) { //se trata el error en lectura
	   perror("read");
	   exit(1);
	   }
	return 0;
}
