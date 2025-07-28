#include <iostream>
#include "dictionary.h"
#include "fundos.h"

using namespace std;

int main() {
	//clb::Console cmd(80, 50, "<<_ECONOMIA_>>");
	utils::PrintColour_("<<_ECONOMIA_>>\n", FBI);

	//cout << "Federa Research (Fed)=> " << economy::search("Federal Research (Fed)") << endl << endl;
	//cout << "aaa                  => " << economy::search("aaa") << endl << endl;
	economy::fundosUsage();

	utils::dicShow("Economy", "Ativo");
	utils::dicShow("Economy", "Passivo");
	utils::dicShow("Economy", "Insider Trading");


	system("pause");
	return(0);
}