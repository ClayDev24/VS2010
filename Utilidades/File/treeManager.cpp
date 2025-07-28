#include <windows.h>
#include <iostream>
#include "treeManager.h"
#include "..\Utilidades\_toUpper.h"
//#include "defines.h"
static int dlevel = 1;

void showTree(int _level, char *_dname) {
	char buf[512];
	memset(buf, 0x00, sizeof(buf));
	memset(buf, ' ', _level*3);

	int i;
	for(i=0; i<_level*3; i+=3)
		buf[i] = '|';	
	buf[i-1] = buf[i-2] = '_';

	printf("\n%s%s", buf, _dname );
	fflush(stdout);
}

utils::CFolder::CFolder(CTreeManager *tree, char *current): m_tree(tree) {
	SetCurrentDirectory(current);	

	std::string s = current;
	int len = s.length();

	if(s.compare(len-1, len, "\\"))
		s += "\\";
	s += "*.*";
	//s += m_tree->m_mask;

	Hnd = FindFirstFile(s.c_str(), &WFD);
	if(Hnd == INVALID_HANDLE_VALUE) {
		std::cout << "File/Folder NOT found!\n"; 
		return;
	}
	walkdir();
};

void utils::CFolder::walkdir() {
	char fullPath[512];//MAX_PATH];
	
	do { // loop throught the current directory
		GetCurrentDirectory(512, fullPath);
		int  size = sizeof(fullPath);
		// Put a '\' char when needed:
		if (strncmp(&fullPath[size - 1], "\\", 1))
			strcat_s(fullPath, size, "\\");
		
		// Create full path:
		strcat_s(fullPath, size, WFD.cFileName);
		// Directory:
		if((WFD.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
			(strcmp(WFD.cFileName, "..") && strcmp(WFD.cFileName, "."))) {
				dlevel++;
				if(m_tree->m_show)
					showTree(dlevel, WFD.cFileName);
				m_tree->m_folders.push_back(fullPath);//WFD.cFileName);
				// Walk SUBDIRECTORIES:
				if(m_tree->m_sub)
					CFolder folder(m_tree, fullPath);
				dlevel--;
				// Go back one level
				SetCurrentDirectory("..");
		} else // File:
			if((strcmp(WFD.cFileName, "..") && strcmp(WFD.cFileName, "."))) { // Skip this kinda files
				// Sortin' by tha mask:				
				std::string extension = WFD.cFileName;
				utils::_str2Lower(extension);

				int pos = extension.find_last_of(".");
				// Se *todas ou a máscara passa:
				if((m_tree->m_mask[0] == '*') || (!extension.substr(pos+1).compare(m_tree->m_mask))) {
					m_tree->m_files.push_back(fullPath);//WFD.cFileName);
					//m_tree->m_files.push_back(WFD.cFileName);
					dlevel++;
					if(m_tree->m_show)
						showTree(dlevel, WFD.cFileName);
					dlevel--;
				}				
			}
	} while(FindNextFile(Hnd, &WFD));
	FindClose(Hnd);

}

// ***************** <<_USAGE_>> *****************
void utils::cTreeManagerUsage() {
	using namespace std;
	//CTreeManager tree("C:\\", true, true, "*");
	//CTreeManager tree("I:\\Teste", true, true, "txt");
	CTreeManager tree("I:\\CODES\\Languages\\CPP\\Projects\\VS2010\\include", true, true, "*"); // (folder, subfolder, show, mask)
	vetorStr files   = tree.getFiles();
	vetorStr folders = tree.getFolders();

	//utils::_showVetor(files);
	//utils::_showVetor(folders);

	cout << "\ntotalFiles  : " << files.size()   << endl;
	cout <<   "totalFolders: " << folders.size() << endl;
}
