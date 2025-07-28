// <<_LED_>>
#include "led.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese"); // Habilita a acentuação para o português

	utils::PrintColour_("<<_LED_>>\n\n", FRI);

	electro::LEDUsage();

	system("pause");
	return(0);
}

