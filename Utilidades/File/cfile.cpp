#include "cfile.h"
#include "utils.h"

utils::CFile::CFile(std::string Name, FLAG _flag):m_name(Name), m_flag(_flag) {
	//std::cout << "CFile()...\n";
	if(m_flag == READ) {
		std::string line;
		m_byteSz =0; // Sz in bytes
		m_lineSz =0; // Sz in lines
		m_wordsSz=0; // Sz in words
		calculateSize(m_name.c_str()); // in bytes

		infile.open(m_name.c_str());
		if(!infile.is_open()) {
			std::cout << "Unable to open file";
			exit(1);
		}
		texto = new(std::nothrow)std::string[m_byteSz];
		utils::_testMemory(texto);
		while(getline(infile, line))  // Discards newline char
			texto[m_lineSz++] = line; // + "\n";
		infile.close();
			
		calculateSize(m_name.c_str());
	} else
		if(m_flag == WRITE)
			Open4Writing(m_name.c_str());
}
// Size in bytes:
void utils::CFile::calculateSize(const char* _file) {
	// *******Obtaining file size********
	long begin, end;
	infile.clear();
	infile.open(_file);
	begin = static_cast<long>(infile.tellg());
	infile.seekg(0, std::ios::end);
	end = static_cast<long>(infile.tellg());
	infile.close();
	m_byteSz = end - begin;
	//std::cout << "size is: " << m_byteSz << " bytes.\n";	
}

void utils::CFile::Open4Writing(const char* _file) {
	using namespace std;
	// Open direct by its constructor, that in turns make a implicity call to open() func:
	//ofstream myfile("example.bin", ios::out | ios::app | ios::binary);
	ofile.open(_file);
	// Cheks if open func successed:
	if(ofile.is_open()) {
		ofile << "This is a line.\n";
		ofile << "This is another line.\n";
		ofile.close();
	} else cout << "Unable to open file";
}

// ***************** <<_USAGE_>> *****************
void utils::cfileUsage() {

	CFile file("main.cpp", READ);
	//file.printFile();
	std::string *txt = file.getTexto();
	//for(int i=0; i<file.getLineSz(); i++)
	//	P_(txt[i])
	vetorStr *v = file._getLines();
	for(unsigned int i=0; i<v->size(); i++)
		std::cout << v->at(i) << std::endl;
	delete v;
	//file.copyFile2File("main.cpp", "copy.txt");
}

