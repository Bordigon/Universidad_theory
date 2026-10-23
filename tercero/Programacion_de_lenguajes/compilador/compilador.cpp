#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int overflow =1;
int fOverflow(){return overflow--;}
bool enCadena = false;
bool finCadena = false;
int enComentario = 0; 	// si es 1 es porque se encontró un "/" y se busca un *, si tiene un 2 es que tiene un * y se busca otro * y así
int palabraReservada = 0;
std::string buffer;

std::vector<std::string> palabrasReservadas = {
		"if",
		"echo",
		"prompt",
		"function",
		"return",
		"let",
		"string",
		"void",
		"boolean",
		"int",
		"float"
};

std::vector<std::string> simComentarios = {
		" ",
		"/",
		"*",
		"*",
		"/"
};

int simbolos(std::string lexema, std::string charti){
	return 0;
}

int enAlgo(std::string p){
	int result = 0;
	if(!enComentario && p == "\'"){
		if(enCadena)
			finCadena = !finCadena;
		enCadena = !enCadena;
		return 1;
	} else if(simComentarios[enComentario] == p && !enCadena){
		enComentario++;
		if(enComentario == 4)
			enComentario = 0;
	} else if(enComentario%2 == 1 && !enCadena){
		if(enComentario == 1)
			buffer += "/";
			enComentario = 0;
	}
	return enCadena || enComentario || finCadena;
}



int identificador(std::string p){
	int result = 0;
	int encontrado = 0;
	if(p == "/'" || p == "/" || p == "*")
		enAlgo(p);
	else{
		for(const std::string& pprr : palabrasReservadas){
			result++;
			if(pprr == p){
				encontrado = result;
				palabraReservada = result;
				break;
			}
		}
	}
	return encontrado;	
}


int main(int argc, char* argv[]){
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2]);
	std::string lexema;
	std::string aux;
	char charti;
	int count = 0;

	while(in.get(charti) || fOverflow()!=0){
		count++;
		std::cout << charti << std::endl;
		
		if(enAlgo(aux=charti)){
			buffer += charti;
			if(finCadena){
				std::cout <<"<cadena," <<buffer<<">";
				finCadena = !finCadena;
			}
		} else if(simbolos(lexema, aux = charti)){
			std::cout << "se ignoró" + charti << std::endl;
		} else if(identificador(lexema)){
			lexema=charti;
		} else if(charti == ' ' && palabraReservada){
			out << "<" << 	palabrasReservadas[palabraReservada] << "," << lexema << ">";
			lexema = "";
		} else lexema += charti;		

	}	
}








