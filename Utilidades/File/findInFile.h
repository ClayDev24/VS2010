#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "treeManager.h"

namespace utils {

	class CFind {

		utils::CTreeManager m_tree;
		vetorStr            m_files;
		int				    m_found;
	public:
		CFind(char* _file, char* _mask = "*"):m_tree(_file, true, true, _mask), m_found(0) {};
		~CFind() {};
		void search(std::string _str, bool _sensivity=false) {
			using namespace std;
			if(!_sensivity) // not CASE SENSIVITY:
				transform(_str.begin(), _str.end(), _str.begin(), ::toupper);

			vetorStr files = m_tree.getFiles();
			for(unsigned int i=0; i<files.size(); i++) {
				string file = files[i];
				ifstream in(file.c_str(), ifstream::in);
				string line;

				while(getline(in, line)) {
					if(!_sensivity) // not CASE SENSIVITY:
						transform(line.begin(), line.end(), line.begin(), ::toupper);

					size_t at=line.find(_str); // find at line
					if (at!=string::npos) {
						m_files.push_back(file); 
						m_found++;					
						std::cout << file << std::endl;
						cout << "Line " << (i+1) << ": " << line /*m_lines[i]*/ << endl;		
						cout << "found at column: " << int(at) << endl;	
					}
				}
				m_files.clear();
				in.close();
			}
		}
		int totalFolders() { return m_tree.totalFolders(); }
		int totalFiles()   { return m_tree.totalFiles();   }
		int totalFound()   { return m_found; }
		vetorStr Files()   { return m_files; }
	};
	// ***************** <<_USAGE_>> *****************
	static void cFindUsage() {
		using namespace std;
		//CFind find("I:\\Músicas\\Lyrics", "lrc"); // Case Non-sensivity
		CFind find("I:\\Programming\\CPP\\VS2010\\Resume", "cpp"); // Case Non-sensivity
		find.search("friend ostream&", false);
		std::cout << std::endl;
		utils::_showVetor(find.Files());
		cout << "Total files: " << find.totalFiles() << endl;
		cout << "Total found: " << find.totalFound() << endl;
	}

} // utils