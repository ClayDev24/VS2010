// Fonte: <https://view.officeapps.live.com/op/view.aspx?src=https%3A%2F%2Fwww%2Eanbima%2Ecom%2Ebr%3A443%2Fdata%2Ffiles%2F5C%2FF6%2FAA%2F5A%2FCB942810FE9D5328882BA2A8%2FEstatistica%2520de%2520Varejo%2520202206%2Exlsx>
#include <iostream>
#include <string>
#include "utils.h"

// INDEXES:
#define MAX_ROWS    8
#define MAX_COLUMNS 3
#define TOTAL	1 // Todos os estados
#define SP		2

namespace economy {

	// TOTAL Geral:	 2.896.264,5 (investidores)
	// 1. FUNDOS DE INVESTIMENTO 555 / FMP: 597.122,2 (total geral) 
	std::string FUNDOS_DE_INVESTIMENTO_555_FMP [MAX_ROWS][MAX_COLUMNS] = {
		// Fundos:								total:597.122,2  SP: 269.301,2 
		{"Renda Fixa"							,"367823.5"		,"155224.1"}, 
		{"Renda Fixa (Baixa Dura��o)"			,"244507.2"		,"98559.6" },
		{"Renda Fixa (Exceto Baixa Dura��o)"	,"123316.4"		,"56664.5" },
		{"Multimercados"						,"177896.1"		,"89149.1" },
		{"A��es"								,"43310.3"		,"21243.9" },
		{"FMP"									,"5863.8"		,"2658.1"  },
		{"Cambial"								,"2228.6"		,"1025.9"  },
		{"","",""}
	};

	// 2- FUNDOS ESTRUTURADOS (ETF's): 87.936,9 (total geral)
	//std::string FUNDOS_ESTRUTURADOS_ETF [6][2] = {
	//	 ETF's:													total por fundo
	//	{"fundo de investimento em direitos credit�rios (fidc)",	"5701.5"},
	//	{"fundo de investimento imobili�rio (fii)",					"69780.6"}, 
	//	{"fundo de investimento em participa��es (fip)",			"7558.5"}, 
	//         etf total: 4.896,4 
	//	{"etf renda fixa",											"252.3"},
	//	{"etf renda vari�vel",										"4644.1"},
	//	{"",""} 
	//};

	// 3. T�TULOS E VALORES MOBILI�RIOS: 1.257.348,9 (total geral) 
	//std::string TITULOS_E_VALORES_MOBILI�RIOS [][] = {
	//    Renda Vari�vel: 185.469,1 (total geral) 
	//        A��es	 185469.1 
	//    Renda Fixa: 1.038.272,2 (total geral) 
	//     Titulos P�blicos	 95720.0 
	//            Pr�-Fixado	 13393.7 
	//            P�s-Fixado	 30951.8 
	//            H�brido		 51374.4 
	//     Titulos Privados	 942552.2 
	//        CDB/RDB	 574930.3 
	//        Op. Compromissada	 4842.3 
	//        Letras de Cr�dito Agr�cola (LCA)	 153.127,3 
	//        Certificado de Receb�veis Agr�colas (CRA)	 29.138,9 
	//        Letras Hipotec�rias (LH)	 -   
	//        Letras de Cr�dito Imobili�rio (LCI)	 109.152,6 
	//        Certificado de Receb�veis Imobili�rios (CRI)	 13.777,8 
	//        Letras Financeiras (LF)	 7.878,5 
	//        Deb�ntures	 38.889,9 
	//            Deb�ntures Tradicionais	 10.760,1 
	//            Deb�ntures Incentivadas	 28.129,8 
	//        BOX	 283,0 
	//        Letra Imobili�ria Garantida (LIG)	 7.808,8 
	//        Letra de Arrendamento Mercantil (LAM)	 16,9 
	//        Letra de C�mbio (LC)	 2.338,1 
	//        Outros	 367,8 
	//   H�brido	 33.607,6 
	//       Certificado de Opera��es Estruturadas (COE)	 33.607,6 
		
	static std::string search_fundos(const std::string matrix[][3], int rows, int cols, const std::string& key) {
		int size=MAX_PARES;
		bool found = false;
		for (int i=0; i < size; ++i) {
			if (matrix[i][0] == key) {
				return matrix[i][1]; // Retorna o valor correspondente � chave
			} else if(matrix[i][0]=="")
				break;
		}
		return "Chave n�o encontrada";
	}

	float printMatrix(const std::string matrix[][3], int rows, int cols) {
		using namespace std;
		float total = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
			total+=utils::_strTo<float>(matrix[i][1].c_str());
		}
		utils::PrintColour("Total Geral: ", FBI); cout << total;
		return total;
	}

	// ***************** <<_USAGE_>> *****************
	void fundosUsage() {
		//utils::PrintColour_(
		utils::dicShow("economy", "Fundos de Investimentos");

		//cout << "Renda Fixa: " << search_fundos(FUNDOS_DE_INVESTIMENTO_555_FMP, 7, 2, "Renda Fixa") << "(Total de investidores no Brasil.)\n";
		float total = printMatrix(FUNDOS_DE_INVESTIMENTO_555_FMP, 8, 3);
		std::cout << std::endl;
		//cout << "etf renda fixa: " << search_fundos(FUNDOS_ESTRUTURADOS_ETF, 5, 2, "etf renda fixa") << "(Total de investidores no Brasil.)\n";
		//total = printMatrix(FUNDOS_ESTRUTURADOS_ETF, 5, 2);
		std::cout << std::endl;
	}


	//4. POUPAN�A [2]	 953.856,5 
	//	
	//	
	//        Fundos de A��es - 157 [4]	 1.131,6 
	//        Poupan�a (Saldo <= R$ 100,00) [3]	 1.543,8 
	//	
	//VAREJO TRADICIONAL[1] [2]	 1.606.089,0 
	//	
	//1. FUNDOS DE INVESTIMENTO 555 / FMP [1]	 219.613,3 
	//	
	//2. FUNDOS ESTRUTURADOS / ETF	 36.172,4 
	//	
	//3. T�TULOS E VALORES MOBILI�RIOS	 534.552,1 
	//	
	//4. POUPAN�A [2]	 815.751,2 
	//	
	//VAREJO ALTA RENDA [1] [2]	 1.290.175,5 
	//	
	//1. FUNDOS DE INVESTIMENTO 555 / FMP [1]	 377.508,9 
	//	
	//2. FUNDOS ESTRUTURADOS / ETF	 51.764,5 
	//	
	//3. T�TULOS E VALORES MOBILI�RIOS	 722.796,8 
	//	
	//4. POUPAN�A [2]	 138.105,3

}


 //44.982,3 

 //1.317,6 
 //34.918,1 
 //6.319,3 
 //2.427,3 
 //144,7 
 //2.282,5 

 //532.014,2 

 //81.218,8 
 //81.218,8 
 //433.525,8 
 //44.541,2 
 //6.596,3 
 //13.678,9 
 //24.266,0 
 //388.984,6 
 //229.200,6 
 //2.751,3 
 //57.678,3 
 //15.143,7 
 //-   
 //46.498,6 
 //7.502,0 
 //4.012,4 
 //20.267,0 
 //4.907,0 
 //15.360,0 
 //75,5 
 //4.560,9 
 //15,2 
 //1.117,0 
 //162,0 
 //17.269,6 
 //17.269,6 

 //304.731,7 





 //521.261,8 

 //80.930,5 

 //16.430,3 

 //185.012,2 

 //238.888,8 

 //629.767,6 

 //188.370,7 

 //28.552,1 

 //347.002,0 

 //65.842,8 