#include "linguagem.h"

int main() {
	using namespace utils;

	math::linguagem();

	PrintColour_("Tip1=> 35% 80 == 80% de 30", FRI);
	PrintColour_("Tip2=> 20% de x == (x/10) *2. Ex.: 20% de 80=> (80/10)*2 = 8*2 = 16", FRI);

	PrintColour_("Tip3=> Comparação entre frações: Multiplicar cruzado. Os resultados são referêntes aos nominadores " \
		          "de cada fração. Ex.: 1/2 e 1/5 = 2 e 5 (o resultado 5 saiu da multiplicação entre o nominador da fração 1/2)", FRI);

	PrintColour_("Tip4=> Interpretação de problemas: As preposições de, do e da = multiplicação" \
				  "Ex.: 1/3 de 45 = 1/3 x 45", FRI);

	PrintColour_("Tip4=> Interpretação de problemas: As preposições por = divisão" \
				  "Ex.: 2 por 3 = 2/3. 30% = 30/100", FRI);

	system("pause");
	return(0);
}