#pragma once
#include <iostream>
#include <fstream> // Open files for readin' n' writin' operations
#include <string>  // getline()
#include "_getLines.h"
#include "_getWords.h"

namespace utils {

	enum FLAG{
		READ=0,
		WRITE
	};

	class CFile {

	private:
		std::string   m_name;
		std::ifstream infile;
		std::ofstream ofile;
		std::string   *texto;
		int  m_flag;   // READ / WRITE
		int  m_byteSz; // Sz in bytes
		int  m_lineSz; // Sz in lines
		int  m_wordsSz;// Sz in words
		void calculateSize(const char* Arquivo);
		void Open4Writing(const char* Arquivo);
	public:
		CFile(std::string Name, FLAG Flag);
		~CFile() {
			delete []texto;
			//std::cout << "~CFile()...\n";
		}
		void printFile() {
			for(int i=0; i<m_lineSz; i++)
				std::cout << texto[i] << std::endl;
		}
		void copyFile2File(char* _from, char* _to) {
			using namespace std;
			ifstream  in(_from);// Open for reading
			ofstream out(_to);	// Open for writing
			string s;
			while(getline(in, s))	//, 'a')) // Discards newline char. The terminator character can be changed!
				out  << s << endl;	// ... must add it back
			in.close();
			out.close();
		}
		std::string *getTexto() { return texto; }
		int getLineSz() { return m_lineSz; }
		vetorStr* _getWords() { return utils::_getWords(m_name.c_str()); }
		vetorStr* _getLines() { return utils::_getLines(m_name.c_str()); }
	};
	// ***************** <<_USAGE_>> *****************
	void cfileUsage();

}; // utils