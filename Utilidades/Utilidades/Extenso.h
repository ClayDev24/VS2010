#pragma once
#include <string>
#include <iostream>

namespace utils {

	class Extenso {
		// unidade / dezena / centena:
		std::string ordem(signed long long Number);
	public:
		std::string convert(signed long long Number);
	};
	// ***************** <<_USAGE_>> *****************
	void ExtensoUsage();

} // utils
