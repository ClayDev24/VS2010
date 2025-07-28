#include <algorithm> // sort()
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <sstream>
#include "Tokenizer.h"
#include "_randomWords.h"

using namespace std;

vector<string> tokenize(const string &str, const string &delimiters) {
    vector<string> tokens;
    size_t start = 0, end = 0;

    while ((end = str.find_first_of(delimiters, start)) != string::npos) {
        if (end != start) {
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str.length()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

utils::Tokenizer::Tokenizer(string _str, string _del):m_phrase(_str), m_delimiters(_del) {
	m_tokens   = 0;
	m_size     = 0;
	m_capacity = 0;
	start();
}

utils::Tokenizer::~Tokenizer() {
	delete []m_tokens;
	//cout << "~Tokenizer()..." << endl;
}

void utils::Tokenizer::start() {
	string str = "";
	for(unsigned int i = 0; i < m_phrase.size(); i++) {
		str += m_phrase[i];
		bool found = false;
		if(m_delimiters.find(m_phrase[i]) != -1) {
			found = true;
			if(!(i == m_phrase.size())) {
				if(str.size() > 1) {
					str = str.substr(0, str.size() - 1);                  					
					if(m_capacity == m_size)
						inflate();
					m_tokens[m_size] = str;
					m_size++;
				}
				str = "";
			}
		}
		if(i == m_phrase.size() - 1) {
			if(found)
				str = str.substr(0, str.size() -1);
			if(!(str.size() == 0)) {				
				if(m_capacity == m_size) 
					inflate();
				m_tokens[m_size] = str;
				m_size++;
				str = "";
			}
		}
	}
}

void utils::Tokenizer::inflate() {
	m_capacity += 10;
	string *temp = new string[m_capacity];
	for(int i = 0; i < m_size; i++)
		temp[i] = m_tokens[i];
	delete[] m_tokens;
	m_tokens = temp;
}

string utils::Tokenizer::get_at(int index) {
	if(index < 0 || index > (m_size - 1))
		return "invalid index";
	return m_tokens[index];
}
// ***************** <<_USAGE_>> *****************


void utils::TokenizerUsage() {
	//Tokenizer2 *token = new utils::Tokenizer2("Claudio Marcio Ferreira da Silva", "aeiou ");//, "aeiouAEIOU");
	//Tokenizer token("Claudio Marcio Ferreira da Silva Andrade", "aeiou ");
	Tokenizer *token = new utils::Tokenizer("Claudio Marcio Ferreira da Silva", "aeiou ");//, "aeiouAEIOU");

	cout << "size: " << token->get_size() << endl;
	for(int i = 0; i < token->get_size(); i++)
		cout << token->get_at(i) << endl;

	delete token;

	testSpeedy();
	testSpeedy2();
}

void utils::testSpeedy() {
	for(int i=0; i<10; i++) {
		std::string s = utils::_randomWords(1024, 'a', 'z');
		//P_(s)
		Tokenizer token(s, "aeiou");
		for(int i2 = 0; i2 < token.get_size(); i2++)
			;//P_(token.get_at(i2))
	}
}

void utils::testSpeedy2() {
    string input = "Claudio Marcio Ferreira da Silva";
    string delimiters = "aeiou "; // You can use any delimiters you want
    vector<string> tokens = tokenize(input, delimiters);

    // Printing the tokens
	for(unsigned int i=0; i<tokens.size(); i++) 
        cout << tokens[i] << endl;
}