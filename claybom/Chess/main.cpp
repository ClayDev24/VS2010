#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Função para imprimir o tabuleiro
void imprimirTabuleiro(vector<vector<string>> &tabuleiro) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<string>> tabuleiro(8, vector<string>(8));

    // Inicialize o tabuleiro com peças vazias
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = ".";
        }
    }

    // Coloque algumas peças iniciais (exemplo)
    tabuleiro[0][0] = "R"; // Torre branca
    tabuleiro[0][7] = "R"; // Torre branca
    tabuleiro[7][0] = "r"; // Torre preta
    tabuleiro[7][7] = "r"; // Torre preta

    imprimirTabuleiro(tabuleiro);

    // Loop do jogo
    bool jogoAtivo = true;
    while (jogoAtivo) {
        // Aqui você pode implementar a lógica do jogo para permitir que os jogadores façam movimentos
        // Por exemplo, você pode solicitar entradas dos jogadores para determinar os movimentos das peças
        // e atualizar o estado do tabuleiro conforme os movimentos são feitos.

        // Quando um jogador ganhar ou ocorrer um empate, você pode definir jogoAtivo como falso para encerrar o jogo.
    jogoAtivo = false;
	}

	system("pause");
	return 0;
}

/*
#include  <iostream>
#include "Board.h"
using namespace std;

int main() {
	SetConsoleTitle("### CHESS ###");
	//cout << "### DAMAS ###" << endl;
	Board b;

	system("pause");
	return(0);
}
*/