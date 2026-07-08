//Argumentos de programa: son aquellas palabras que van despu'es del .exe al ejecutarlo
//argc cuenta el número de argumentos que van luego de la ejecución
//argv es ela rray desde el cuál se peude acceder a ellos


#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	printf("El argc es de %i\n", argc);
	
	for(int t = 0; argv[t] != NULL; t++)
		printf("%s\n", argv[t]);

//---------------------------- struct --------------------- es un equivalente a los objetos de javscript
	struct Persona{int edad; char nombre[20];};
	struct Persona p = {.edad = 18,.nombre = "estefan'ia"};
	printf("Edad: %i, nombre: %s\n", p.edad, p.nombre);
	p.edad = 19;
	printf("Cumplió años así que ahora tiene %d\n", p.edad);

//---------------------------- typedef -------------------- usado para crear alias
	typedef struct Persona Person;
	Person p2 = {.edad = 21, .nombre = "c'esar"};
	printf("Edad: %i, nombre: %s\n", p2.edad, p2.nombre);
	//las estructuras pueden contener otras estructuras, juega con los puntos, funciona muy intuitivo

//---------------------------- punteros ------------------- arrow functions
	Person *ptr = &p2;
	printf("Edad: %i, nombre: %s      con punteros\n", (*ptr).edad, (*ptr).nombre);
	printf("Edad: %i, nombre: %s      con arrow function\n", ptr->edad, ptr->nombre);	

	system("pause");
	return 0;
}