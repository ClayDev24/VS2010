#pragma once
#include <iostream>

namespace cdate {
	static const char *MONTH_NAMES[] = { 
		"January", "February", "March", "April", "May", "June", "July", 
		"August", "September", "October", "November", "December" 
	};

	static const char *DAY_NAMES[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
		"Friday", "Saturday"
	};

	static const char *DEF_FORMAT = "YYYYMMDD";
}; // namespace cdate

class CDate {
	enum { DPY = 365 };

	unsigned _m, _d, _y;
	unsigned _daycount;

	char *_formatStr;

	void StringToDate(const char *date, const char *fmt);

	void CalcDayCount(); // calc _daycount based on _m, _d, _y
	void CalcMDY();      // calc _m, _d, _y based on _daycount

public:
	CDate();// retrieves current system date  
	CDate(const CDate &rhs);
	CDate(int m, int d, int y);
	explicit CDate(int totalDays);
	explicit CDate(const char *date, const char *fmt=cdate::DEF_FORMAT);
	~CDate();

	// form a date string in the format of fmt (which contains M's, D's, and Y's)
	// note: a sequence of 3 or more M's will cause the name of the month to be
	// used; when using the name, capital M's and lower case m's change the output;
	// if you want the entire month name, use 9 M's to accomodate the longest name
	const char* Format(const char *fmt);
	// it is the programmer's responsibility to insure recvBuf has room for fmt
	const char* Format(const char *fmt, char *recvBuf) const;

	// get the difference between two dates  
	int operator-(const CDate &rhs) const;

	const CDate operator+(int count) const;
	const CDate operator-(int count) const;
	CDate& operator+=(int count);
	CDate& operator-=(int count);
	const CDate operator++(int);
	const CDate operator--(int);
	CDate& operator++();
	CDate& operator--();

	operator const char*()                    { return Format(cdate::DEF_FORMAT); }
	operator const char*() const;

	int GetDayOfWeek() const;// where 0=SUN, 1=MON, ...

	int GetMonth() const                    { return _m; }
	int GetDay() const                      { return _d; }
	int GetYear() const                     { return _y; }
	int GetDayCount() const                 { return _daycount; }  
	const char* GetMonthName() const        { return cdate::MONTH_NAMES[_m]; }
	const char* GetDayName() const          { return cdate::DAY_NAMES[GetDayOfWeek()]; }

	void SetMonth(int m)                    { _m = m; CalcDayCount(); }
	void SetDay(int d)                      { _d = d; CalcDayCount(); }
	void SetYear(int y)                     { _y = y; CalcDayCount(); }
	void SetDayCount(int dc)                { _daycount = dc; CalcMDY(); }

	bool operator==(const CDate &rhs) const { return _daycount == rhs._daycount; }
	bool operator!=(const CDate &rhs) const { return !operator==(rhs); }
	bool operator<(const  CDate &rhs) const { return _daycount < rhs._daycount; }
	bool operator>(const  CDate &rhs) const { return _daycount > rhs._daycount; }
	bool operator<=(const CDate &rhs) const { return operator<(rhs) && operator==(rhs); }
	bool operator>=(const CDate &rhs) const { return operator>(rhs) && operator==(rhs); }

	friend std::ostream& operator<<(std::ostream &out, const CDate &cd) { return out << (const char*)cd; }
	// we'll leave it up to the user to decide how to read a date then properly format it into a CDate
};

static void cDateUsage() {
	using namespace std;
	CDate date; // retrieves current date
	cout << "Today is " << date.GetDayName() << ", " << date << endl;// print weekday name

	date += 28; // set date to 28 Days Later using operator+=()

	const char *today = "20031118";

	if (date != CDate(today)) {// construct using const char* then compare with operator!=()
		cout << date.Format("Mmmmmmmmm DD, YYYY") << " is not today!\n";
		// print difference between two dates and print dates with user-defined formats    
		cout << "There are " << (date - CDate(today)) << " days between " << 
			date.Format("MM/DD/YY") << " and " << CDate(today).Format("mm/dd/yy\n");
	}

	// print today's date using default format (which is "yyyymmdd")  
	cout << "\nToday is: " << CDate() << endl;

	// print today's weekday name and date with user-defined format
	cout << "Or more nicely put, today is: " << CDate().GetDayName() << ", " <<
		CDate().Format("Mmm DD, yyyy") << endl;
}