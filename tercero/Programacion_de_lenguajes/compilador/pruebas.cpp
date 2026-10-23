#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int overflow =1;
int fOverflow(){return overflow--;}
bool enCadena = 0;
bool enComentario = 0;
bool enAlgo(){ return enCadena || enComentario;}


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
		"=<",
		"=>",
		"==",
		"!=",
		"int",
		"float"
};



int identificador(std::string palabra){
	int result = -1;
	int encontrado = 0;
	if(palabra == "\'" || palabra == "/")
		enCadena++;	

	else{
	for(const std::string& p : palabrasReservadas){
		result++;
		if(p == palabra){
			encontrado = 1;
			break;
		}
	}}
	if(encontrado){
		return result;
	}else
		return encontrado;
}



int main(int argc, char* argv[]){

	std::ifstream in(argv[1]);
	std::ofstream out(argv[2]);
	std::string lexema;
	std::string aux;
	char charti;	
	int count = 0;


	while(in.get(charti) || fOverflow()!= 0){ 
		count++;
		std::cout << lexema<<count<<overflow << std::endl;
		if(enAlgo()){
			identificador(aux=charti);
			if(!enAlgo())
		}
		else if(identificador(lexema)){
			if(enAlgo())
				break;
			else{
			out << "<"<< palabrasReservadas[identificador(lexema)]<<",->"  << "\n";
			lexema = "";}
		}

		else if(identificador(aux=charti) || charti == ' ' || overflow == 0){
			if(lexema.length())
				out <<"<lexema,"<< lexema<<">" << "\n";
			lexema = "";
			if(identificador(aux=charti)){
				out << "palabra reservada" << "\n";
				charti='\0';
			}
		}
		
		else
			lexema += charti;		
			//out << charti << "\n";
		

	}
	return 0;
}