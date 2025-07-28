#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Tokenizer.h"

using namespace std;

CTokenizer::CTokenizer(string phrase, string delimiters) {
    m_phrase     = phrase;
    m_delimiters = delimiters;
	m_tokens     = 0;
    m_size       = 0;
	m_capacity   = 0;
    start();
}

CTokenizer::~CTokenizer() {
	delete []m_tokens;
}

void CTokenizer::start() {
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

void CTokenizer::inflate() {
	m_capacity += 10;
	string *temp = new string[m_capacity];
	for(int i = 0; i < m_size; i++)
		temp[i] = m_tokens[i];
	delete[] m_tokens;
	m_tokens = temp;
}

string CTokenizer::get_at(int index) {
	if(index < 1 || index > (m_size))
		return "invalid index";
	return m_tokens[--index];
}

short CTokenizer::get_size() {
    return m_size;
}

int main() {
	CTokenizer *token = new CTokenizer("Claudio Marcio Ferreira da Silva Andrade", "aeiou ");
	cout << "size: " << token->get_size() << endl;
	for(int i = 0; i < token->get_size(); i++)
		cout << token->get_at(i) << endl;
	
	system("pause");
	return(0);
}


