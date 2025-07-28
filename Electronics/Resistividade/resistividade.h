#pragma once
#include "utils.h"

// Material (metais, ligas metálicas, semicondutores e isolantes): /
// -Símbolo químico: /
// -Número atômico: /
// -Peso específico em grama por cm³: /
// -Ponto de fusão em °C: /
// -Resistividade em ohms x mm² / m (a 20°C):

char *resistividadeTABLE[] = {
	"| Alumínio (99.9%)                       | Al | 13 | 2.580  | 657   | 0.0284     |",
	"| Alumínio temperado                     | –  | –  | 2.703  | 658   | 0.0288	  |",
	"| Alumínio                               | –  | –  | 2.699  | 660   | 0.0278	  |",
	"| Antimônio                              | Sb | 51 | 6.691  | 631   | 0.4170	  |",
	"| Arsênio                                | As | 33 | 5.727  | 817   | 0.3000	  |",
	"| Bismuto                                | Bi | 83 | 9.780  | 271   | 1.3000	  |",
	"| Berílio                                | Be | 4  | 1.848  | 1287  | 0.0400	  |",
	"| Borracha                               | –  | –  | –      | –     | 1017	      |",
	"| Boro                                   | B  | 5  | 2.460  | 2076  | 1.8 x 1018 |",
	"| Bromo                                  | Br | 35 | 3.120  | -7.2  | 1024	      |",
	"| Bronze-Alumínio/(Cu 90% – Al 10%)      | –  | –  | 7.600  | 1050  | 0.1259	  |",
	"| Cádmio                                 | Cd | 48 | 8.65   | 321   | 0.0700	  |",
	"| Cálcio                                 | Ca | 20 | 1.550  | 842   | 0.0340	  |",
	"| Carbono                                | C  | 6  | 2.267  | 3527  | 3000	      |",
	"| Chumbo                                 | Pb | 82 | 11.30  | 327   | 0.2114	  |",
	"| Cobalto                                | Co | 27 | 8.900  | 1495  | 0.0600	  |",
	"| Cobre eletrolítico                     | Cu | 29 | 9.050  | 1080  | 0.0167     |",
	"| Cobre recozido normal                  | –  | –  | 8.890  | 1085  | 0.0173	  |",
	"| Constantan/(Cu 60% – Ni 40%)           | –  | –  | 8.400  | 1240  | 0.5000	  |",
	"| Cromo                                  | Cr | 24 | 7.140  | 1907  | 0.1270	  |",
	"| Ebonite                                | –  | –  | –      | –     | 1013	      |",
	"| Enxofre                                | S  | 16 | 1.960  | 115   | 1021	      |",
	"| Estanho                                | Sn | 50 | 7.30   | 231   | 0.1195	  |",
	"| Ferro puro comercial                   | Fe | 26 | 7.85   | 1538  | 0.0970	  |",
	"| Ferro fundido                          | –  | –  | 7.874  | 1500  | 0.9200	  |",
	"| Ferro-níquel                           | –  | –  | 8.100  | 1500  | 0.8126	  |",
	"| Fósforo                                | P  | 15 | 1.823  | 44.2  | 0.1000	  |",
	"| Gálio                                  | Ga | 31 | 5.904  | 29.8  | 0.1400	  |",
	"| Germânio                               | Ge | 32 | 5.323  | 938   | 46 x 104   |",
	"| Índio                                  | In | 49 | 7.310  | 156   | 0.0800	  |",
	"| Iodo                                   | I  | 53 | 4.940  | 114   | 1.3 x 1021 |",
	"| Irídio                                 | Ir | 77 | 22.650 | 2466  | 0.0470	  |",
	"| Latão/(Cu 60% – Zn 40%)                | –  | –  | –      | –     | 0.0818	  |",
	"| Lítio                                  | Li | 3  | 0.535  | 180   | 0.094	  |",
	"| Maillechort/(Cu 60% – Ni 15% – Zn 25%) | –  | –  | 8.600  | 1500  | 0.0534	  |",
	"| Magnésio                               | Mg | 12 | 1.738  | 650   | 0.0440	  |",
	"| Manganês                               | Mn | 25 | 7.470  | 1246  | 1.6000	  |",
	"| Manganina/(Cu 84% – Mn 12% – Ni 4%)    | –  | –  | 8.30   | –     | 0.4200	  |",
	"| Mercúrio                               | Hg | 80 | 13.55  | -38.3 | 0.9567	  |",
	"| Mica                                   | –  | –  | –      | –     | 1015	      |",
	"| Molibdênio                             | Mo | 42 | 10.28  | 2623  | 0.0500	  |",
	"| Nióbio                                 | Nb | 41 | 8.570  | 2477  | 0.1500	  |",
	"| Níquel                                 | Ni | 28 | 8.70   | 1452  | 0.0780	  |",
	"| Níquel-Cromo/(Cu 60% – Cr 12% – Fe 28%)| –  | –  | –      | –     | 1.3700	  |",
	"| Niquelina/(Cu 62% – Ni 18% – Zn 20%)   | –  | –  | –      | –     | 0.3320	  |",
	"| Niquelina/(Cu 55% – Ni 25% – Zn 20%)   | –  | –  | –      | –     | 0.4527	  |",
	"| Ósmio                                  | Os | 76 | 22.5   | 3033  | 0.0949	  |",
	"| Ouro                                   | Au | 79 | 19.3   | 1064  | 0.022	  |",
	"| Parafina                               | –  | –  | –      | –     | 1023	      |",
	"| PET                                    | –  | –  | –      | –     | 1026	      |",
	"| Platina                                | Pt | 78 | 21.5   | 1768  | 0.1184	  |",
	"| Polônio                                | Po | 84 | 9.196  | 254   | 0.4300	  |",
	"| Porcelana                              | –  | –  | –      | –     | 1015	      |",
	"| Potássio                               | K  | 19 | 0.856  | 63.4  | 0.0700	  |",
	"| Prata                                  | Ag | 47 | 10.49  | 962   | 0.0158	  |",
	"| Quartzo/(fundido)                      | –  | –  | –      | –     | 7.5 x 1023 |",
	"| Selênio                                | Se | 34 | 4.819  | 221   | 0.1200	  |",
	"| Silício                                | Si | 14 | 2.330  | 1414  | 64 x 107   |",
	"| Sódio                                  | Na | 11 | 0.96   | 97.8  | 0.0470	  |",
	"| Tálio                                  | Tl | 81 | 11.850 | 303   | 0.1500	  |",
	"| Tântalo                                | Ta | 73 | 16.65  | 3017  | 0.3361	  |",
	"| Teflon                                 | –  | –  | –      | –     | 1028 a 1030|",
	"| Telúrio                                | Te | 52 | 6.240  | 449   | 1010	      |",
	"| Titânio                                | Ti | 22 | 4.507  | 1668  | 0.4000     |",
	"| Tungstênio                             | W  | 74 | 19.250 | 3422  | 0.0710	  |",
	"| Vanádio                                | V  | 23 | 6.110  | 1910  | 0.2000	  |",
	"| Vidro                                  | –  | –  | –      | –     | 1016 a 1020|",
	"| Zinco                                  | Zn | 30 | 2.33   | 67.6  | 0.765	  |",
	"| Zircônio                               | Zr | 40 | 1.85   | 84.4  | 0.612	  |", 0};

// Para utiilizar a fórmula da RESISTIVIDADE, multiplicamos a resistividade pelo comprimento e dividimos pela área da secção reta do condutor.
// Por exemplo. um condutor de Zircônio de 2 metros de comprimento e seção de 0.4 mm2 terá uma resistência de:

// (R)esistance = Resistividade x Area (mm2) / lenght (m)
// R = 0.612 * 0.4 / 2 = 0,122 Ohm-meter

namespace elec {
	static float _displayResistividadeTABLE() {
		using namespace std;
		//vetorStr v;

		int i=0;
		while(resistividadeTABLE[i]) {
			char *str = resistividadeTABLE[i++];
//			P_(str)

			utils::Tokenizer *token = new utils::Tokenizer(str, "|");//, "aeiouAEIOU");
//			cout << "size: " << token->get_size() << endl;
			for(int i=0; i<token->get_size(); i++)
				cout << token->get_at(i) << endl;

			delete token;
		}
		return 0;
	}
} // elec