#include "vetorComparison.h"
#include "_showVetor.h"

// ***************** <<_USAGE_>> *****************
void utils::VetorComparisonUsage() {
	using namespace utils;
	vetorInt vi1, vi2, vi3;
	for(int i=0; i<10; i++) {
		vi1.push_back(i);
		vi2.push_back(i+5);
	}
	vi3 = vetorComparison(vi1, vi2, "match");
	_showVetor(vi3);
	vi3 = vetorComparison(vi1, vi2, "miss");
	_showVetor(vi3);
	vi3 = vetorComparison<vetorInt>(vi1, vi2, "match");
	_showVetor(vi3);
	vi3 = vetorComparison<vetorInt>(vi1, vi2, "miss");
	_showVetor(vi3);

	vetorChr vc1, vc2, vc3;
	for(int i=97; i<=107; i++) {
		vc1.push_back(i);
		vc2.push_back(i+5);
	}
	vc3 = vetorComparison(vc1, vc2, "match");
	_showVetor(vc3);
	vc3 = vetorComparison(vc1, vc2, "miss");
	_showVetor(vc3);
	vc3 = vetorComparison<vetorChr>(vc1, vc2, "match");
	_showVetor(vc3);
	vc3 = vetorComparison<vetorChr>(vc1, vc2, "miss");
	_showVetor(vc3);

	vetorLng vl1, vl2, vl3;
	//for(long i=97; i<=107; i++) {
	//	vl1.push_back(i);
	//	vl2.push_back(i+5);
	//}
	vl1.push_back(2);
	vl1.push_back(2);
	vl1.push_back(2);
	vl1.push_back(3);
	vl1.push_back(3);
	vl1.push_back(4);
	vl2.push_back(2);
	vl2.push_back(2);
	vl2.push_back(2);
	vl2.push_back(3);
	vl2.push_back(3);
	vl2.push_back(4);

	vl3 = vetorComparison(vl1, vl2, "match");
	_showVetor(vl3);
	std::cout << "\n";
	vl3 = vetorComparison(vl1, vl2, "miss");
	_showVetor(vl3);
	vl3 = vetorComparison<vetorLng>(vl1, vl2, "match");
	_showVetor(vl3);
	vl3 = vetorComparison<vetorLng>(vl1, vl2, "miss");
	_showVetor(vl3);
}