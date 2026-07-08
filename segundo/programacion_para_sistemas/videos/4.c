//funciones
//punteros

#include <stdlib.h>
#include <stdio.h>


void cambio(int *c, int *d); //las funciones tienen que ser predeclaradas como si se trataran de una interfaz o una variable sin inicializar

int main(){

	int x, *y;

	x = 4;
	y = &x;
	//*y es un puntero, y recibe una direccion de memoria
	//al usar "y", esto nos devolver'a la direcci'on de memoria de "x"
	//pero al usar "*y" nos devolver'a el valor de "x"

	printf("Los valores de x es: %i, y es: %i\n\n", x, *y);

	int a, b;

	a = 1;
	b = 5;
	printf("Valor de las variables precambio(), a = %i, b = %i \n\n", a, b);

	cambio(&a, &b);

	printf("Valor de las variables postcambio(), a = %i, b = %i \n\n", a, b);
	

	system("pause");
	return 0;
}


void cambio(int *c, int *d){
	int aux;

	aux = *c;
	*c=*d;
	*d=aux;

}