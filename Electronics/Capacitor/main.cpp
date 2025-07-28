// <<_CAPACITOR_>>
#include "capacitor.h"
using namespace std;
using namespace elect;

int main() {
	setlocale(LC_ALL, "Portuguese"); // Habilita a acentuação para o português
	int *pStripe;
	int  size;

	cout << "<<_CAPACITOR_>>\n\n" << endl;
/*
top:
	cout << "How many digits has the capacitor?: ";
	cin >> size;

	pStripe = new (std::nothrow) int[size];

	if(!pStripe)
		cout << "Error: memory could not be allocated\n";
	else 
		for(int i=0; i<size; i++)
			cin >> pStripe[i]; // Always left one left room spare. (in a 4 stripes case)

	clb::PrintColour("", FRI, 0);

	CCapacitor *C1 = new CCapacitor(*pStripe, size);
	C1->print();

	//C1->m_tolerance(4);

	delete C1;

	char ch = 'a';
	while(toupper(ch) != 'N') {
		std::cout << "again? (y/n):\n";
		ch = toupper(getche());
		if(ch == 'Y') goto top;
	}
*/	
	elect::capacitorUsage();

	system("pause");
	return(0);
}

