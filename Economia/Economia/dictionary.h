#pragma once
#include <iostream>
#include <string>
#include "utils.h"

namespace economy {

	static const int MAX_PARES = 100; // Defina o número máximo de pares chave/valor

	/* lista de palavras e significados */
	static std::string dictionary[][2] = {
		{"Milton Friedman", "Laureado com o Prêmio Nobel de Economia e o mais articulado porta-voz do livre mercado \
concordaria que mercados sem restrições (laissez faire) podem levar a resultados profundamente falhos."
		},
		{"Economia Comportamental", "Explora como os indivíduos tomam decisões- às vezes de maneiras não tão racionais \
quanto as previstas nas teorias econômicas."
		},
		{"Objetivo da economia nos indivíduos", "Maximilizar nossa utilidade dados os excassos recursos disponíveis"
		},
		{"Objetivo das empresas", "Maximilizar os (seus) lucros."
		},
		{"Lucro", "Rendimento obtido na venda dos produtos menos o custo de produção."
		},
		{"Maximilização de lucro", "É o preço no qual se fixa o preço de mercadol."
		},
		{"Federal Research (Fed)", "O banco central americano."
		},
		{"O livre mercado (vulgo capitalismo)", "Sistema de trocas livres (sem regulamentação) responsável direto e indireto \
pela melhoria da qualidade de vida da humanidade: \
Ex.: Em 1972 uma tv colorido de 25pol nos EUA custava 174 horas de trabalho. Em uma tv de mesmo tamanho e com qualidade e resoluções \
infinitamente superiores custam em média 23 horas de trabalho. \
Ex2.: Durante o século XXa expectativa de vida americana subiu de 47 para 77 anos, a mortalidade infantil foi reduzida \
em 95%, e foram erradicadas, ou pelo menos controladas, doenças como pólio, tuberculose, tifo e coqueluxe."
		},
		{"Custo real", "É aquilo que vc precisa abdicar para obter esta coisa. Normalmente o dinheiro, mas pode ir além, como o tempo."
		},
		{"Preço de Mercado", "É o ponto em que se estabiliza a oferta e a demando. Ou seja, não sobra (pelo preço alto) \
e nem falta (pelo preço baixo) produtos no estoque."
		},
						   // Preços de mercado para Grifes=> Não há preços de mercado para grifes. A Gap (marca de roupas americana) por exemplo,
						   // por se tratar de uma grife famosa não possui um 'preço de mercado' para seus produtos. As blusas Gap não se enquadram na categoria "blusas gerais" e portanto a marca em si já é um diferencial.
						   // No entanto a Gap, ainda assim, terá um preço de lucro maximilizado, ou seja, um preço em quie a oferta e a demanda se estabilizam. E logicamente, este preço será maior do que o preço de mercado.

						   // Discriminação de preçoas=> Vender o mesmo item para pessoas diferentes a preços diferentes. (Ex.: passagens aéreas)

						   // O sistema capitalista usa os PREÇOS para alocar recursos escassos (já que existe uma quantidade limitada de recursos).
						   // Lei da oferta e procura: Fixa os preços no valor de mercado.
						   // Tanto o comunismo qnto o capitalismo racionam bens (um mediante preços, outro filas)

						   // O mercado é como a evolução: extrai sua força recompensado o ágil, o forte e o esperto. (eg.: as duas espécies mais adaptadas do planeta são o rato e a barata).

						   // Cartel: São conluios entre empresas que detém um oligopólio, com o intuito de limitar a produção de determinado bem ou comodite e aumentar o seu preço.

						   // Preços tabelados fazem a qualidade nos serviços e produtos melhorarem (como forma de diferencial na competição pela preferênc9a)

						   // política pública- Leis que o estado faz para ajudar os cidadãos a tomar as melhores atitudes para seus bem-estar, as quais eles por si só não conseguiriam sozinhos (analogia da castanha*)
						   // *Analogia da dastanha- Richard Thaler foi anfitrião de um jantar no qual serviu uma tigela de castanhas-de-caju antes da refeição. Ele notou que seus convidados avançavam nas castanhas com tamanha avidez, que provavelmente lehes estragaria o apetite para o jantar. Então Thaler mandou tirar a tigela de castanhas, e nesse ponto os convidados lhe agradeceram.

						   // Custo de Oportunidade-> Cada escolha implica uma renúncia à outras. Optamos pelo ganho de uma escolha ao mesmo tempo que abdicamos pelos ganhos da outra opção não escolhida.

		{"", ""} /* nulo termina a lista */
	};

	static std::string search(const std::string& key) {
		int size=MAX_PARES;
		bool found = false;
        for (int i=0; i < size; ++i) {
            if (dictionary[i][0] == key) {
                return dictionary[i][1]; // Retorna o valor correspondente à chave
            } else if(dictionary[i][0]=="")
				break;
			std::cout << i << std::endl;
        }
        return "Chave não encontrada";
    }

}