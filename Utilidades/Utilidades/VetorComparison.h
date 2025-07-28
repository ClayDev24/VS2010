#pragma once
#include <string>

namespace utils {

	template <class T>
	T vetorComparison(const T &vtA, const T &vtB, std::string Opt) {
		T vtMatch, vtMiss;

		bool miss = true;
		for(unsigned int a=0; a<vtA.size(); a++) {
			for(unsigned int b=0; b < vtB.size(); b++)
				if(vtA.at(a) == vtB.at(b)) {
					vtMatch.push_back(vtA.at(a));
					miss = false;
				}
				if(miss)
					vtMiss.push_back(vtA.at(a));
				miss = true;
		}

		if(Opt == "miss")
			return vtMiss;
		return vtMatch;
	};
	// ***************** <<_USAGE_>> *****************
	void VetorComparisonUsage();

} // utils