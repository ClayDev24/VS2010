#pragma once
#include <string>
#include "Pattern.h"

namespace utils {
/*
	static bool comparisonPair(const std::pair<int,int> &a, const std::pair<int,int> &b) {
		return a.first > b.first; 
	} 
	static bool comparisonUnique(const std::pair<int,int> &a, const std::pair<int,int> &b) {
		return a.first == b.first; 
	} 
*/
	class CFindPatterns {
		std::vector<utils::CPattern> m_data;
		STR  m_phrase;
		bool m_sorting;
		bool m_subscript;
	public:
		CFindPatterns(STR Phrase, const int &_n, bool Subscript=true, bool sorting=true);
		~CFindPatterns() {}
		//inline void setSubscript(bool _b) { m_subscript=_b; }
		//inline std::string getPattern()   { return m_pattern;     }
		//inline int getSize()              { return m_data.size(); }
		void find(const int _n);
		void show();//bool Unique=true);
		//void setSort(bool _s) { m_sort=_s; }
	};
	// ***************** <<_USAGE_>> *****************
	void _findPatternsUsage();

}; // utils
