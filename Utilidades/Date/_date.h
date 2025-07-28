#pragma once
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include <ctime>

namespace utils {

	static std::string _date(const char *_code, bool _show=true) {
		time_t t = time(nullptr);
		struct tm time_info;
		char   str[150];

		int error = localtime_s(&time_info, &t);
		if(!error) { // se zero
			strftime(str, sizeof(str), _code, &time_info);
			if(_show)
				std::cout << str << std::endl;
		} else
			std::cout << "error code: " << error << std::endl;

		std::string s = str;
		return s;
	}

	static void _dateUsage() {
		std::string s =
		_date("Abbreviated weekday name:               %a", false); // Thu
		std::cout << s.c_str() << std::endl;
		_date("Full weekday name:                      %A"); // Thursday
		_date("Abbreviated month name:                 %b"); // Aug
		_date("Full month name:                        %B"); // August
		_date("Date and time representation:           %c"); // Thu Aug 23 14:55:02 2001
		_date("Day of the month, zero-padded (01..31): %d"); // 23
		_date("Hour in 24h format (00-23):             %H"); // 14
		_date("Hour in 12h format (01-12):             %I"); // 02
		_date("Day of the year (001-366):              %j"); // 235
		_date("Month as a decimal number (01-12):      %m"); // 08
		_date("Minute (00-59):                         %M"); // 55
		_date("AM or PM designation	PM:                %p"); 
		_date("Second (00-61):                         %S"); // 02
		_date("Week number with the first Sunday as the first day of week one (00-53): %U"); // 33
		_date("Weekday as a decimal number with Sunday as 0 (0-6):                     %w"); // 4
		_date("Week number with the first Monday as the first day of week one (00-53): %W"); // 34
		_date("Date representation:                    %x"); // 08/23/01
		_date("Time representation:                    %X"); // 14:55:02
		_date("Year, last two digits (00-99):          %y"); // 01
		_date("Year:                                   %Y"); // 2001
		_date("ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100) If timezone cannot be determined, no characters +100: %z");
		_date("Timezone name or abbreviation. If timezone cannot be determined, no characters	CDT: %Z");
	}

} // utils