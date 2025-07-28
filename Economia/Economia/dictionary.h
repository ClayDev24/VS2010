#pragma once
#include <iostream>
#include <string>
#include "utils.h"

namespace economy {

	static const int MAX_PARES = 100; // Defina o n�mero m�ximo de pares chave/valor

	/* lista de palavras e significados */
	static std::string dictionary[][2] = {
		{"Milton Friedman", "Laureado com o Pr�mio Nobel de Economia e o mais articulado porta-voz do livre mercado \
concordaria que mercados sem restri��es (laissez faire) podem levar a resultados profundamente falhos."
		},
		{"Economia Comportamental", "Explora como os indiv�duos tomam decis�es- �s vezes de maneiras n�o t�o racionais \
quanto as previstas nas teorias econ�micas."
		},
		{"Objetivo da economia nos indiv�duos", "Maximilizar nossa utilidade dados os excassos recursos dispon�veis"
		},
		{"Objetivo das empresas", "Maximilizar os (seus) lucros."
		},
		{"Lucro", "Rendimento obtido na venda dos produtos menos o custo de produ��o."
		},
		{"Maximiliza��o de lucro", "� o pre�o no qual se fixa o pre�o de mercadol."
		},
		{"Federal Research (Fed)", "O banco central americano."
		},
		{"O livre mercado (vulgo capitalismo)", "Sistema de trocas livres (sem regulamenta��o) respons�vel direto e indireto \
pela melhoria da qualidade de vida da humanidade: \
Ex.: Em 1972 uma tv colorido de 25pol nos EUA custava 174 horas de trabalho. Em uma tv de mesmo tamanho e com qualidade e resolu��es \
infinitamente superiores custam em m�dia 23 horas de trabalho. \
Ex2.: Durante o s�culo XXa expectativa de vida americana subiu de 47 para 77 anos, a mortalidade infantil foi reduzida \
em 95%, e foram erradicadas, ou pelo menos controladas, doen�as como p�lio, tuberculose, tifo e coqueluxe."
		},
		{"Custo real", "� aquilo que vc precisa abdicar para obter esta coisa. Normalmente o dinheiro, mas pode ir al�m, como o tempo."
		},
		{"Pre�o de Mercado", "� o ponto em que se estabiliza a oferta e a demando. Ou seja, n�o sobra (pelo pre�o alto) \
e nem falta (pelo pre�o baixo) produtos no estoque."
		},
						   // Pre�os de mercado para Grifes=> N�o h� pre�os de mercado para grifes. A Gap (marca de roupas americana) por exemplo,
						   // por se tratar de uma grife famosa n�o possui um 'pre�o de mercado' para seus produtos. As blusas Gap n�o se enquadram na categoria "blusas gerais" e portanto a marca em si j� � um diferencial.
						   // No entanto a Gap, ainda assim, ter� um pre�o de lucro maximilizado, ou seja, um pre�o em quie a oferta e a demanda se estabilizam. E logicamente, este pre�o ser� maior do que o pre�o de mercado.

						   // Discrimina��o de pre�oas=> Vender o mesmo item para pessoas diferentes a pre�os diferentes. (Ex.: passagens a�reas)

						   // O sistema capitalista usa os PRE�OS para alocar recursos escassos (j� que existe uma quantidade limitada de recursos).
						   // Lei da oferta e procura: Fixa os pre�os no valor de mercado.
						   // Tanto o comunismo qnto o capitalismo racionam bens (um mediante pre�os, outro filas)

						   // O mercado � como a evolu��o: extrai sua for�a recompensado o �gil, o forte e o esperto. (eg.: as duas esp�cies mais adaptadas do planeta s�o o rato e a barata).

						   // Cartel: S�o conluios entre empresas que det�m um oligop�lio, com o intuito de limitar a produ��o de determinado bem ou comodite e aumentar o seu pre�o.

						   // Pre�os tabelados fazem a qualidade nos servi�os e produtos melhorarem (como forma de diferencial na competi��o pela prefer�nc9a)

						   // pol�tica p�blica- Leis que o estado faz para ajudar os cidad�os a tomar as melhores atitudes para seus bem-estar, as quais eles por si s� n�o conseguiriam sozinhos (analogia da castanha*)
						   // *Analogia da dastanha- Richard Thaler foi anfitri�o de um jantar no qual serviu uma tigela de castanhas-de-caju antes da refei��o. Ele notou que seus convidados avan�avam nas castanhas com tamanha avidez, que provavelmente lehes estragaria o apetite para o jantar. Ent�o Thaler mandou tirar a tigela de castanhas, e nesse ponto os convidados lhe agradeceram.

						   // Custo de Oportunidade-> Cada escolha implica uma ren�ncia � outras. Optamos pelo ganho de uma escolha ao mesmo tempo que abdicamos pelos ganhos da outra op��o n�o escolhida.

		{"", ""} /* nulo termina a lista */
	};

	static std::string search(const std::string& key) {
		int size=MAX_PARES;
		bool found = false;
        for (int i=0; i < size; ++i) {
            if (dictionary[i][0] == key) {
                return dictionary[i][1]; // Retorna o valor correspondente � chave
            } else if(dictionary[i][0]=="")
				break;
			std::cout << i << std::endl;
        }
        return "Chave n�o encontrada";
    }

}