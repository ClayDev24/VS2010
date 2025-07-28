#pragma once
#include "Dictionary.h"
#include "_colour.h"
#include "..\Console\console.h"
#include "_toUpper.h"

utils::Dictionary::Dictionary(std::string _file, std::string _pasta):m_file(_file), m_pasta(_pasta) {
	setlocale(LC_ALL, "Portuguese");
	// Initialize with predefined entries
	//utils::DictionaryEntry entradas;
	//entradas.keyword = "keyword1";
	//entradas.meaning = "meaning1";
	//entries.push_back(entradas);
	load(); // from file
}

// Method to search for a keyword and return its meaning
std::string utils::Dictionary::search(std::string _key) {//const std::string& keyword) {
	for (unsigned int i = 0; i < entries.size(); i++) {
		if (entries.at(i).keyword == _key) {
			return entries.at(i).meaning;
		}
	}
	return "Keyword not found in the dictionary.";
}

// Method to sort the dictionary by keyword
void utils::Dictionary::sort() {
	std::sort(entries.begin(), entries.end(), [](const DictionaryEntry& a, const DictionaryEntry& b) {
		return a.keyword < b.keyword;
	});
}

// Method to display all items in the dictionary
void utils::Dictionary::displayAll() {
	for (unsigned int i = 0; i < entries.size(); i++) {
		std::cout << "Keyword: " << entries.at(i).keyword << " - Meaning: " << entries.at(i).meaning << std::endl;
	}
}

// Method to save the dictionary entries to a text file
void utils::Dictionary::save() {//const char* _filename) {
	std::string fullPath = m_pasta;
	fullPath += m_file;
	std::ofstream file(fullPath);
	if (file.is_open()) {
		for(unsigned int i = 0; i < entries.size(); i++) {
			file << entries.at(i).keyword << '#' << entries.at(i).meaning << '\n';
		}
		file.close();
		std::cout << "Dictionary saved to " << m_file << std::endl;
	}
	else {
		std::cerr << "Error: Unable to open the file for writing." << std::endl;
	}
}

// Method to load dictionary entries from a text file
void utils::Dictionary::load() {
	std::string fullPath = m_pasta;
	fullPath += m_file;

	std::ifstream file(fullPath);
	if (file.is_open()) {
		entries.clear(); // Clear existing entries
		std::string line;
		while (std::getline(file, line)) {
			size_t commaPos = line.find('#');
			if (commaPos != std::string::npos) {
				DictionaryEntry entry;
				entry.keyword = line.substr(0, commaPos);
				entry.meaning = line.substr(commaPos + 1);
				entries.push_back(entry);
			}
		}
		file.close();
		//std::cout << "Dictionary loaded from " << filename << std::endl;
	}
	else {
		std::cerr << "Error: Unable to open the file for reading." << std::endl;
	}
}
// **************<<_USAGE_>>****************
void utils::dictionaryUsage() {

	Dictionary dicionario("economy.txt");
	// Search for a keyword
	const char* key = "N�mero M�gico";
	std::cout << "Meaning of '" << key << "': " << dicionario.search(key) << std::endl;

	// Sort the dictionary by keyword
	dicionario.sort();

	// Display all items in the dictionary
	std::cout << "All Entries in the Dictionary:" << std::endl;
	dicionario.displayAll();
}

void utils::dicShow(std::string dicName, std::string dicType) {

	std::string title = dicName;
	utils::_str2Upper(title);
	title = "<<_" + title + "_>>";
	utils::Console cmd(125, 34, title.c_str());//"<<_MATHEMATICS_>>");
	cmd.setBufferSize(125, 200);

	std::string file = dicName;
	file += ".txt";
	utils::Dictionary dicionario(file.c_str());//"mathematics.txt");

	// Search for a keyword
	std::string type = dicType;
	type = "<<_" + type + "_>>";
	utils::PrintColour(type.c_str(), BRI);
	utils::PrintColour_(dicionario.search(dicType.c_str()).c_str(), FYI);
	cmd.setColour(FGI);
	std::cout << std::endl;
}

void utils::dicShowUsage() {

	dicShow("mathematics", "Abs");

}
