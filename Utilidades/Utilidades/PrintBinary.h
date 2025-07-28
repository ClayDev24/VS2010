#pragma once

namespace utils {
	
	void PrintBinary(const unsigned char &_ch, const char &_fill = '_');
	void PrintBinaryDouble(double &_d, const char &_fill = '_');
	void PrintBinaryInt(int &_i, const char &_fill = '_');
	void PrintBinaryLongLong(long long &_ll, const char &_fill = '_');

	// ***************** <<_USAGE_>> *****************
	void PrintBinaryUsage();
	
}; // utils
