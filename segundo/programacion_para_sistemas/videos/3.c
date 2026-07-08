//do-while
//fflush(stdin)
//el programa no acaba hasta que le das una "s"
//el do-while SIEMPRE se ejecutar'a 1 vez aunque la condición no se cumpla

#include <stdlib.h>
#include <stdio.h>

int main(){

	char c;

	do{
		printf("Introduce una letra: ");
		//en C cuando tu das ´enter´ para introducir un dato el programa te lo guarda como búfer
		//x lo q hay que limpiarlo
		fflush(stdin);//este es el limpiador
		scanf("%c", &c);
		

	}while(c != 's');

	system("pause");
	return 0;
}