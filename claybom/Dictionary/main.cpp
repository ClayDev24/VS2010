/* Um dicionário simples. */
#include "vld.h"
#include "utils.h"

/* lista de palavras e significados */
char *dic[][40] = {
	"atlas",    "um livro de mapas",
	"carro",    "um veiculo motorizado",
	"telefone", "um dispositivo de comunicaçao",
	"aviao",    "uma maquina voadora"
	//"", "" /* nulo termina a lista */
};

int main() {
	using namespace std;
	//char word[80];
	string word;
	char **p;
	do {
		word = utils::_inputWord();
		p = (char**)dic;
		/* encontra a palavra e imprime seu significado */
		do {
			if(!strcmp(*p, word.c_str())) {
				cout << "significado: ";
				puts(*(p+1));
				break;
			}
			p += 2; /* avança na lista */
		} while(*p);
		if(!*p)
			cout << "a palavra nao esta no dicionario\n";
		cout << "again? (y/n): ";
	} while(toupper(_getche()) != 'N');

	system("pause");
	return(0);
}