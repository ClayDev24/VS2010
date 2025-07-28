#include <algorithm> // sort()
#include <iostream>
#include <conio.h>
#include <vector>
#include "CStr.h"
#include "_randomWords.h"
//#include "utils.h"
#include "defines.h"
using namespace std;

utils::CStr::CStr(const char *_str) {
	m_capacity = 21; // tamanho inicial do buffer
	m_buffer   = new char[m_capacity];
	//P_(sizeof(m_buffer))
	memset(m_buffer, 'a', sizeof(char)*m_capacity);
	int i = 0;
	do {
		m_buffer[i] = _str[i];
	} while(_str[i++]);
	m_size = i-1;
	P_(m_size)

	start();
}

utils::CStr::~CStr() {
	delete []m_buffer;
	//cout << "~CStr()..." << endl;
}

void utils::CStr::start() {

}

void utils::CStr::inflate() {
	m_capacity += 10;
	string *temp = new string[m_capacity];
	for(int i = 0; i < m_size; i++)
		temp[i] = m_buffer[i];
	delete[] m_buffer;
//	m_buffer = temp;
}

char* utils::CStr::get_at(int index) {
	if(index < 0 || index > (m_size - 1))
		return "invalid index";
	return &m_buffer[index];
}
// ***************** <<_USAGE_>> *****************


void utils::CStrUsage() {
	// Heap usage:
//	CStr *frase = new utils::CStr("Claudio Marcio Ferreira da Silva");
//	cout << "size: " << frase->get_size() << endl;
//	for(int i = 0; i < frase->get_size(); i++)
//		cout << frase->get_at(i) << endl;

//	delete frase;

	// Stack usage:
	CStr c("Clailton");
	cout << c << endl;
	char *ch = c.get_at(2);
	cout << ch << endl;
	testMemory2();
}

void utils::testMemory2() {
	for(int i=0; i<1000; i++) {
		std::string s = utils::_randomWords(25, 'a', 'z');
		//P_(s)
		CStr c(s.c_str());
		cout << c << endl;
	}
}