//arrays
//números aleatorios

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void introducir(int a[]);
void imprimir(int a[]);
void ejemplo(int a[][5]);

int main(){

	int v[] = {1, 2, 3, 4};
	int w[4];
	//algo muy curioso es que al pasar el Nombre del array es equivalente a que le enviaras la direcci'on de memoria
	//x lo que los m'etodos void si que pueden cambiar ese valor 

	introducir(w);
	imprimir(w);

	//hacer referencia a un elemento de un array
	printf("El 'ultimo elemento de w es: %i\n", w[3]);

	//hacer referencia a un elemento de un array x puntero
	printf("El 'ultimo elemento de w es: %i\n", *(w+3));

	//plus, "srand" genera una semilla aleatoria global en todo el programa
	srand (time(NULL)); 
	//"rand()" usa dicha semilla par agenerar un n'umero aleatorio, C no est'a orientado a objetos as'i que no guarda relaci'on con "srand"
	//"rand()" genera un n'umero aleatorio, y luego por ariem'etica modular hacemos que ese n'umero sea entre 0 y 6
	int aux = rand()%6;

	//en una matriz la diferencia con java es que al hacer una funci'on que reciba dicha matriz hay que...
	int matriz[5][5];
	ejemplo(matriz);
	
	system("pause");
	return 0;

}

//m'etodo por nombre
void introducir(int a[]){
	for (int i = 0; i<4; i++)
		a[i]=i;
}

//m'etodo por puntero
void imprimir(int *a){
	for(int i = 0; i<4; i++)
		printf("%i\n",*(a+i));
}

void ejemplo(int a[][5]){//hay que poner el tama;o de de las columnas si o si, siempre en los m'etodos que reciben matrices

}