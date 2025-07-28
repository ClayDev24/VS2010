#include <iostream>
#include "aliquota.h"
#include "irpf.h" // contribuinte.h
#include "utils.h"
using namespace std;

int main() {
	utils::_setLocale();
	//clb::Console cmd(80, 50, "<<_ECONOMIA_>>");
	utils::PrintColour_("<<_(I)MPOSTO DE (R)ENDA (P)ESSOA (F)ÍSICA_>>\n", FBI);

	//cout << "Federa Research (Fed)=> " << economy::search("Federal Research (Fed)") << endl << endl;
	//cout << "aaa                  => " << economy::search("aaa") << endl << endl;
	economy::_aliquotaUsage();
	//economy::_contribuinteUsage();
	//economy::_irpfUsage();

	system("pause");
	return(0);
}