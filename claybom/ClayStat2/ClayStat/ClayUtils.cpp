#include <string>
#include <cmath>
#include <iostream>
//#include <conio>
#include "ClayUtils.h"

using namespace std;

string clb::int2str(long val) {
   string out = "";
   int size = 1;
   int i = val;   
   int inteiro = val;
   int resto = 0;  
   while((i = i / 10) > 0) 
     size++; 
   char c[10];
   int param = (int)pow(10, size -1);  
   for(i = 0; i < size; i++) {  
      int param = (int)pow(10, size - i - 1);
      resto = inteiro % param;
      inteiro = inteiro / param;
      c[i] = (inteiro + 48);
      out += c[i];
      inteiro = resto;
   }
   return out;
};

//void inflate(string a[], int size) {
//    string[size + 10];
//    for(int i = 0; i < size; i++)
//        out[i] = a[i];
//    a = out;
//};

int clb::split(string &to, char delimitador, string token[], int size) {
//    inflate(token, 0);
    static string out = "";
    int sz = 0;    
    for(int i = 0; true; i++) {
        char ch = to[i];
	if(ch != delimitador && ch != '\n' && ch != '\r' && ch != '\0') {
	    out += ch;
	} else {  
	    if(size == sz) break;	    
	    token[sz++] = out;
	    out = "";
	    if(ch == '\0') 
	        break;
	}
    }    
    return sz;
};

clb::CTokenizer::CTokenizer(string phrase, string delimiters) {
    m_phrase     = phrase;
    m_delimiters = delimiters;
	m_tokens     = 0;
    m_size       = 0;
	m_capacity   = 0;
    start();
}

clb::CTokenizer::~CTokenizer() {
	delete []m_tokens;
}

void clb::CTokenizer::start() {
    string str = "";
	for(unsigned int i = 0; i < m_phrase.size(); i++)
	{
		str += m_phrase[i];
		bool found = false;
		if(m_delimiters.find(m_phrase[i]) != -1)
		{
			found = true;
            if(!(i == m_phrase.size()))
			{
				if(str.size() > 1)
				{
					str = str.substr(0, str.size() - 1);                  					
					if(m_capacity == m_size)
						inflate();
					m_tokens[m_size] = str;
					m_size++;
				}
                str = "";
			}
		}
		if(i == m_phrase.size() - 1)
		{
			if(found) {
				str = str.substr(0, str.size() -1);
			}
			if(!(str.size() == 0))
			{				
				if(m_capacity == m_size) 
					inflate();
				m_tokens[m_size] = str;
				m_size++;
				str = "";
			}
		}
	}
}

void clb::CTokenizer::inflate() {
	m_capacity += 10;
	string *temp = new string[m_capacity];
	for(int i = 0; i < m_size; i++)
		temp[i] = m_tokens[i];
	delete[] m_tokens;
	m_tokens = temp;
}

string clb::CTokenizer::get_at(int index) {
	if(index < 1 || index > (m_size))
		return "invalid index";
	return m_tokens[--index];
}

short clb::CTokenizer::get_size() {
    return m_size;
}

/*
int main() {
	CTokenizer *token = new CTokenizer("Claudio Marcio Ferreira da Silva Andrade", "aeiou ");
	cout << "size: " << token->get_size() << endl;
	for(int i = 0; i < token->get_size(); i++)
		cout << token->get_at(i) << endl;
	getch();
	return 0;
}

int main() {
    string nome("Clailton Ferreira da Silva gosta de fazer flatland...");
    string vt[20];
    int tam = clb::split(nome, ' ', vt, 7);
    cout << "tamanho: " << tam << endl;
    cout << vt[0] << endl;
    cout << vt[1] << endl;
    cout << vt[6] << endl;
    cout << vt[7] << endl;
    cout << vt[8] << endl;
    return 1;
}*/


