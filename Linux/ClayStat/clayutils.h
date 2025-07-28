#include <string>

#ifndef _CLAYUTILS_H
#define _CLAYUTILS_H

namespace clb {

string int2str(long val);
int split(string &to, const char delimitador, string token[], int size);
//vector sort(vector);

class CTokenizer {
	public:
        CTokenizer(std::string phrase, std::string delimiters); 
        ~CTokenizer(); 
		std::string get_at(int index);
        short get_size();
        void reset();
	private:
		void inflate();
		std::string m_phrase;
		std::string m_delimiters;
		std::string *m_tokens;
        short m_size;
		short m_capacity;
        void start();
};

}

//using namespace clb;

#endif //_CLAYUTILS_H

