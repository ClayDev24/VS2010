//#include "vld.h"
#include "test1.h"
#include "utils.h"
using namespace std;

int main() {
	// <<_Chronometer 1_>>
	cout << "<<_Chronometer 1_>>\n\n";
	P_(utils::_chronometer(&clb::_func1))
	// <<_Chronometer 2_>>
	cout << "<<_Chronometer 2_>>\n\n";
	P_(utils::_chronometer(&clb::_func2))

	system("pause");
	return(0);
}
