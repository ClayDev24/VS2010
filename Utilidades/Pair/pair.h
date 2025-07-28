#include <iostream> 
#include <utility> 
#include <algorithm> 
#include <vector> 

namespace utils {

	static bool comparison(const std::pair<int,int> &a, const std::pair<int,int> &b) {
		return a.second < b.second; 
	} 

	static void _pairSorting() {
		using namespace std; 
		// sorting a/c 2 first element beign here 
		std::vector<std::pair<int, int>> vec; 
		int n[] = {8, 1, 4, 3, 5, 2, 6, 7}; 
		int s[] = {10, 20, 30, 40, 50, 60, 70, 80}; 
		int sz = sizeof(n)/sizeof(n[0]); 

		for(int i=0; i<sz;	i++)
			vec.push_back(make_pair(n[i], s[i])); 

		cout << "random vector" << endl; 
		for(int i=0; i<sz; i++)
			cout << vec[i].first << " " << vec[i].second << endl; 

		sort(vec.begin(), vec.end()); 
		cout << "sorted vector a/c to first " << endl; 
		for(int i=0; i<sz; i++)
			cout << vec[i].first << " " << vec[i].second << endl; 

		// sorting a/c 2 second element beign here 
		std::vector< pair<int, int> > vec1; 

		for(int i=0; i<sz;	i++)
			vec1.push_back(make_pair(n[i], s[i])); 

		sort(vec1.begin(),vec1.end(), comparison); 
		cout << "sorted vector a/c to second " << endl; 

		for(int i=0; i<sz; i++)
			cout << vec1[i].first << " " << vec1[i].second << endl; 
	}
} // utils