// ######################### - RENDIMENTOS - ###################################
#include <iostream>
//#include "..\..\Utilidades\Utilidades\Dictionary.h"
#include "utils.h"
#define DE		 0
#define ATE		 1
#define ALIQUOTA 2
#define DEDUCAO  3

namespace economy {

	// TABELA PROGRESSIVA MENSAL:
	// F�rmula: Rendimentos tribut�veis (sal�rio) - Parcela a deduzir = Base de c�lculo. 
	double aliquota_salarial[][4] = { // ROWS X COLUMNS
		// Base de c�lculo (R$)				Al�quota (%)	Dedu��o do IR (R$) // Valor fixo. Sistema progressivo
		{/*de*/0		/*at�*/ ,2259.20	,0				,0		}, // isento
		{/*de*/2259.21	/*at�*/ ,2828.65	,7.5			,169.44 },
		{/*de*/2828.66	/*at�*/ ,3751.05	,15.0			,381.44 },
		{/*de*/3751.6	/*at�*/ ,4664.68	,22.5			,662.77 },
		{/*de*/4664.69	/*at�*/ ,0			,27.5			,896.0  }, // 0 = infinito (acima de 4.664,68
		{/*de*/-1,0,0,0} // fim 
	};

	// fundos de longo prazo e aplica��es de renda fixa em geral
	double aliquota_fundos_renda_fixa[][4] = { // ROWS X COLUMNS
		// De (dias)	At� (dias)			Al�quota (%)	--
		{/*de*/0		/*at�*/ ,180		,22.5			,0 }, // fundos de curto prazo
		{/*de*/180		/*at�*/ ,360		,20.0			,0 }, // fundos de curto prazo
		{/*de*/361		/*at�*/ ,720		,17.5			,0 }, // fundos de LONGO plrazo
		{/*de*/721		/*at�*/ ,0			,15.0			,0 }, // 0 = infinito (acima de 720)
		{/*de*/-1,0,0,0} // fim 
	};

	//Participa��o nos Lucros ou Resultados

	double participacao_lucros_resultados[][4] = {
		// PLR anual (R$)		Al�quota	Dedu��o
		{0			,7407.11	,0			,0		},
		{7407.12	,9922.28	,7.5		,555.53	},
		{9922.29	,13167.00	,15.0		,1299.70},
		{13167.01	,16380.38	,22.5		,2287.23},
		{16380.39	,0			,27.5		,3106.25}, /// 0 = infinito
		{-1,0,0,0} // -1 code = end
	};
	
	// Remessas ao exterior
	double remessas_ao_exterior[][4] = {
		// null		null		Al�quota	null
		{0			,0			,15.0		,0		}, // Demais rendimentos de fontes situadas no Brasil
		{0			,0			,25.0		,0		}, // rendimentos do trabalho, aposentadoria, pens�o por morte ou invalidez e os da presta��o de servi�os,
													   // pagos, creditados, entregues, empregados ou remetidos a n�o residentes
		{-1,0,0,0} // -1 code = end
	};
	
	//Outros rendimentos
	double outros_rendimentos[][4] = {
		// null		null		Al�quota	null
		{0			,0			,1.5		,0		}, // Servi�os de propaganda e remunera��o de servi�os profissionais
		{0			,0			,20.0		,0		}, // Pr�mios e sorteios sob a forma de bens e servi�os
		{0			,0			,30.0		,0		}, // Pr�mios e sorteios em dinheiro
		{-1,0,0,0} // -1 code = end
	};	

	static void _showAliquota(double matrix[][4], const std::string &msg) {
		std::cout << msg.c_str();
		int line=-1;
		std::cout << "De (dias)	at� (dias)	aliquota (%)	--\n";
		std::cout << "Base de c�lculo (R$)		Al�quota (%)	Dedu��o do IR (R$)\n";
		while(matrix[++line][DE] !=-1) {
			std::cout 
				<< matrix[line][DE]			<< "		"
				<< matrix[line][ATE]		<< "		"
				<< matrix[line][ALIQUOTA]	<< "		"
				<< matrix[line][DEDUCAO]	<< std::endl;
		}
	}

	double _calculo_imposto_salarial() {

	}

	// ***************** <<_USAGE_>> *****************
	static void _aliquotaUsage() {
		utils::_setLocale();
		//utils::PrintColour_("<<__AL�QUOT__>>", FBI);
		utils::dicShow("IRPF", "Aliquota");

		// Acessando elementos individualmente:
		std::string msg = "			<<__Aliquota Salarial__>>\n";
		_showAliquota(aliquota_salarial, msg);
		
		msg = "\n	<<__Fundos de Longo Prazo & Aplica��es de Renda Fixa__>>\n";
		_showAliquota(aliquota_fundos_renda_fixa, msg);

		msg = "\n	<<__Participa��o nos Lucros e Resultados__>>\n";
		_showAliquota(participacao_lucros_resultados, msg);		

		msg = "\n	<<__Remessas ao Exterior__>>\n";
		_showAliquota(remessas_ao_exterior, msg);		

		msg = "\n	<<__Outros Rendiemntos__>>\n";
		_showAliquota(outros_rendimentos, msg);		

	}

};
