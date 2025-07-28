#pragma once
#include <string>
#include "utils.h"

namespace utils {

	class CPattern {
		vetorPair m_coords;
		STR  m_pattern;
		STR  m_buffer;
		bool m_subscript;
		void setCoords();
	public:
		CPattern(STR Phrase, STR Pattern = "", bool Subscript=true); 
		~CPattern() {}
		inline STR getPattern() { return m_pattern;      }
		inline int getTotal()   { return m_coords.size();}
		void show(bool Color=true);
		void Color();
	};
	// ***************** <<_USAGE_>> *****************
	void _patternUsage();
	void TestPatterns();

}; // utils
