#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

namespace utils {

	struct DictionaryEntry {
		std::string keyword;
		std::string meaning;
	};

	class Dictionary {
	private:
		std::string m_file;
		std::string m_pasta;
		std::vector<DictionaryEntry> entries;
	public:
		//Dictionary();
		Dictionary(std::string fileName, std::string fileDirectory = "..\\..\\..\\..\\..\\..\\Textos\\dicionários\\");
		//Dictionary(std::string fileName, std::string fileDirectory = "I:\\CODES\\Textos\\dicionários\\");
		// Method to search for a keyword and return its meaning
		std::string search(std::string keyword);
		// Method to sort the dictionary by keyword
		void sort();
		// Method to display all items in the dictionary
		void displayAll();
		// Method to save the dictionary entries to a text file
		void save();
		// Method to load dictionary entries from a text file
		void load();
	};
	// **************<<_USAGE_>>****************
	void dictionaryUsage();
	void dicShow(std::string dicName, std::string dicType);
	void dicShowUsage();
} // ~utils

