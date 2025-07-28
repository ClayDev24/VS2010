#pragma once
#include <string>
#include "utils.h"

namespace utils {

	static bool comparisonPair(const std::pair<int,int> &a, const std::pair<int,int> &b) {
		return a.first > b.first; 
	} 

	static bool comparisonUnique(const std::pair<int,int> &a, const std::pair<int,int> &b) {
		return a.first == b.first; 
	} 

	class CPatterns {
		struct SData {
			CPatterns *dp;
			std::string s_pattern;
			vetorPair   s_coords;
			SData(CPatterns *_dp, std::string _p):dp(_dp), s_pattern(_p) {}
			void show();
			// N. de ocorrências de uma mesma PATTERN:
			int  total() { return s_coords.size(); }
		};
		std::vector<SData> m_data;
		std::string m_pattern;
		char*       m_buffer;
		int  m_sz;
		bool m_subscript;
		bool m_sort;
		void fillCoords(const std::string &_pattern);
	public:
		CPatterns(std::string Phrase, std::string Pattern = "", bool Subscript=true); 
		~CPatterns() { delete []m_buffer; }
		inline void setSubscript(bool _b) { m_subscript=_b; }
		inline std::string getPattern()   { return m_pattern;     }
		inline int getSize()              { return m_data.size(); }
		inline vetorPair   getAt(const unsigned int &_index) {
			utils::require(_index < m_data.size(), "_index < m_data.size()");
			return m_data[_index].s_coords;
		}
		inline void clear() { m_data.clear(); }
		int  findPatterns(const int _n);
		void show(bool Unique=true);
		void setSort(bool _s) { m_sort=_s; }
	};
	// ***************** <<_USAGE_>> *****************
	void _patternsUsage();
	void TestPatterns();

}; // utils
