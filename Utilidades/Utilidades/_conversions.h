#pragma once
#include <sstream> //stringstream()
#include <string>

namespace utils {

	template <typename Type>
	static std::string _toStr(Type _t) {
		std::stringstream ss; 
		std::string       str;  
		ss <<  _t;  
		ss >>  str;
		return str;
	}

	template <typename Type>
	static Type _strTo(const char* _str) {
		Type t;
		std::stringstream(_str) >> t;
		return t;
	}
	// ***************** <<_USAGE_>> *****************
	static void _conversions() {
		using namespace std;
		int             i = _strTo<int>("456");
		float           f = _strTo<float>("4.56");
		double           d = _strTo<double>("4.56");
		unsigned long     l  = _strTo<unsigned long>("4294967295");
		unsigned long long ll = _strTo<unsigned long long>("18446744073709551615");
		cout << i << endl;
		cout << f << endl;
		cout << d << endl;
		cout << l << endl;
		cout << ll << endl;
		string str  = _toStr<int>(888);
		string str2 = _toStr(static_cast<float>(8.88));
		string str3 = _toStr(static_cast<double>(8.88));
		string str4 = _toStr(static_cast<unsigned long>(4294967295));
		string str5 = _toStr(static_cast<unsigned long long>(18446744073709551615));
		cout << str  << endl;
		cout << str2 << endl;
		cout << str3 << endl;
		cout << str4 << endl;
		cout << str5 << endl;
	}

} // utils