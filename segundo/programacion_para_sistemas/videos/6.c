//string
//fgets(array, tama;o, stdin)
//gets(array) este m'etodo es malo x q sobreescribe el espacio en memoria designado al array
//scanf(%s, &array) este m'etodo solo toma el string hasta que hay un espacio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char string[20];

//---------------------------- fgets()--------------

	printf("Escriba una frase:\n");
	fgets(string, 20, stdin);
	
	printf("%s\n\n",string);
//---------------------------- puts() ----------------- solo para cadenas de char, solo en consola

	char ch[] = "hola don pepito";
	printf("%s\n", ch);
	puts(ch);

//---------------------------- putc() ----------------- solo 1 caracter
	
	putc('C', stdout); //salida en terminal
	
	FILE *f;
	
	f = fopen("pruebas.txt", "a+");
	putc('C', f); //salida en archivo

//---------------------------- fputs() ---------------- combinaci'on de ambos, escribe en cualquier parte, cadenas y 1 caracter

	fputs("\nsoy un fputs()\n", stdout); 
	fputs("C\n",stdout);
	fputs("\nfputs() pero en un archivo\n",f);

//---------------------------- fwrite() ---------------  fwrite(direccion_de_memoria, tamaño_de_dato, número_de_datos, file)
	//tama;o ==> sizeof(int), sizeof(char), sizeof(struct x)
	fwrite(string, sizeof(char), strlen(string), f);
	fwrite(string, sizeof(char), strlen(string), stdout);

//---------------------------- fread() ----------------
	rewind(f);
	fread(string,sizeof(char), 20, f);
	string[19]='\0';
	printf("%s", string);	

//---------------------------- strlen(char[]) --------- dice el length del char[]
//---------------------------- strcpy(destino, origen)- copia el char[] origen y lo pone en el char[] destino
//---------------------------- strcat(destino, origen)- el char[] destino recibe el de origen y lo anexa al suyo
	char a[] = "hola";
	char b[] = "mundo";
	strcat(a,b);
	printf("\n%s\n", a);

//---------------------------- strcmp(char[], char[])-- compara ambos y da 0 SI SON iguales
//---------------------------- atoi(char[]) ----------- es un parseInt, se puede inicializar un int con esto
//---------------------------- atof(char[]) ----------- es un parseFloat, se puede init un float con esto



	fclose(f);
	system("pause");
	return 0;
}