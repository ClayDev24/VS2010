#include "tabuada.h"

void math::Tabuada::show(const int &_n) { // 0=all
	using namespace std;
	m_cmd.setColour(BRI);
	cout << "Tabuada do " << _n << ": " << endl;
	m_cmd.setColour(FGI);
	char buf[3];
	for(int a=1; a<10; a++) {
		for(int i=1; i<10; i++) {
			cout.width(3);
			if(i == _n)
				m_cmd.prtColorReturn(itoa((a*i), buf, 10), FRI);
			else
				cout << (a*i);
		}
		cout << endl;
	}
}
// **************<<_USAGE_>>****************
void math::_tabuada() {
	Tabuada tab;
	tab.show(6); // 0=all
}