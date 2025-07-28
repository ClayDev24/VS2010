#pragma once
#include <string>
#include <cstdlib>

namespace clb {

	class Conversions {
		enum { // See EnumHack
			NIBBLE = 4,
			BYTE   = 8,
			WORD   = 16,
			DWORD  = 32,
			QWORD  = 64
		};
		// defaults to private:
	public:
		unsigned long bin2dec (char *bin);
		unsigned long bin2dec2(char *bin);
		std::string   dec2bin (int   dec);
		char* dec2bin2(unsigned int  dec);
		char* dec2bin3(signed   int  dec);
		char* hex2bin (char *hex);
		char* bin2hex (char *hex);
		char* zero_extend(char *bin, int sz, char spacer = 0);
		char* sign_extend(char *bin, int sz, char spacer = 0);

		int    str2int    (const char* _str) { return atoi(_str); }
		float  str2float  (const char* _str) { return static_cast<float>(atof(_str)); }
		double str2double (const char* _str) { return atof(_str); }
		int    str2int2   (const char* _str);
		float  str2float2 (const char* _str);
		double str2double2(const char* _str);
	};

} // clb
