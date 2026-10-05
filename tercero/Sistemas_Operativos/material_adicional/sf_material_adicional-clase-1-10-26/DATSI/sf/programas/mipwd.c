#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	long tam_path = pathconf(".", _PC_PATH_MAX);
	char buf[tam_path]; 
	/* imprime el directorio actual */
	printf("%s\n", getcwd(buf, tam_path));
	return 0;
}
