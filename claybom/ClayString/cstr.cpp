#include <string>
#include <vector>
#include "cstr.h"
#include "utils.h"
using namespace std;

clb::CStr::CStr(char *_s) {
	m_buf = new Mem(strlen(_s)+1); // +1 = zero terminated string
	strcpy((char*)m_buf->pointer(), _s);
	DS_(CStr()...)
}

void clb::CStr::concat(char *_s) {
	if(!m_buf) m_buf = new Mem;
	strcat((char*)m_buf->pointer(m_buf->size()+strlen(_s)+1), _s);
}

void clb::CStr::print(ostream &_os) {
	if(!m_buf) return;
	_os << m_buf->pointer() << endl;
}
// ***************** <<_USAGE_>> *****************
void teste1();
void teste2();

void clb::CStrUsage() {
	//teste1();
	teste2();
}

void teste1() {
	clb::CStr s("My test string");
	s.print(cout);
	s.concat(" some additional stuff");
	s.print(cout);

	char* word;
	std::string str;
	{
		clb::CStr *s2 = new clb::CStr();
		s2->concat("Using default constructor");
		s2->print(cout);

		word = s2->c_str();
		str  = s2->c_str();
		P_(word)
		P_(str)

		int len = strlen(word);
		P_(len)
		P_(static_cast<int>(word[len]))
		delete s2;
	}
	//word = s2.ptr();
	P_(word)
	P_(str)
}

void teste2() {
	vector<clb::CStr> v;
	clb::CStr c1("aaa");
	//v.push_back(c1);//clb::CStr("aaa"));
	//v.push_back(clb::CStr("bbb"));
	//v.push_back(clb::CStr("ccc"));

	//P_(static_cast<char*>(v[0].c_str()))
	std::cout << "HERE" << std::endl;
	//utils::_showVetor(v);
}