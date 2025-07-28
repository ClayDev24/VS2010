#pragma once
#include <string>

namespace utils {

	class Tokenizer{			
		void inflate();
		std::string m_phrase;
		std::string m_delimiters;
		std::string *m_tokens;
		int m_size;
		int m_capacity;
		void start();
	public:
		Tokenizer(std::string Phrase, std::string Delimiters = " "); 
		~Tokenizer(); 
		std::string get_at(int index);
		inline int get_size() { return m_size; }
		void reset();
	};
	// ***************** <<_USAGE_>> *****************
	void TokenizerUsage();
	void testSpeedy();
	void testSpeedy2();

}; // utils
