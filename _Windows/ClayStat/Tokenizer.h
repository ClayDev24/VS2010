
#if !defined(AFX_TOKENIZER_H__B45151BF_8BB5_47AD_802C_A738E586F031__INCLUDED_)
#define AFX_TOKENIZER_H__B45151BF_8BB5_47AD_802C_A738E586F031__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

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

#endif // !defined(AFX_TOKENIZER_H__B45151BF_8BB5_47AD_802C_A738E586F031__INCLUDED_)
