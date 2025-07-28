#ifndef _SDATE_H
#define _SDATE_H

///////////////////////////////////////////////////////////////////////////////////////
/*
	Creates a sdate class to enable users to manipulate dates.
	Can display in "dd/mm/yyyy" format 
	or long format as "monthname day, year"
	
	Takes care of the leap year.
	Makes extensive use of operator overloading.
	(	say 		sdate s1;
	 	preferred:	cout<<s1;	or	s1++;
	 	rather than: s1.show();	or	s1.next();
	) 
*/
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <time.h>

//char meses[][12] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez" };

class sdate
    {
    private:
    	int day;
    	int month;
    	int year;
    	int days_in_month;
    	void operator+(const sdate& d1);
    	//addition of 2 dates not allowed
    	//so its a private member funcation
    	char* mname(int month) const;
    	//returns the name of the month
    public:
    	sdate();
    	//default constructor
    	//initializes date object to system-date by default
    	sdate(int dd, int mm, int yy);
    	//initializes date object to the valued inputted by the user
    	sdate(const sdate& d);
    	//copy constructor
    	sdate& operator=(const sdate& d);
    	//allows assignment of the date object to the given date
    	int operator==(const sdate& d) const;
    	//returns 1 if the date object is equal to the given date
    	int operator!=(const sdate& d) const;
    	//returns 1 if the date object is not equal to the given date
    	int operator<(const sdate& d) const;
    	//returns if the date object comes before the given date
    	int operator>(const sdate& d) const;
    	//returns if date object comes after the given date
    	sdate& operator++();	//prefix increment operator
    	sdate operator++(int);	//postfix increment operator
    	sdate& operator--();	//prefix decrement operator
    	sdate operator--(int);	//postfix decrement operator
    	sdate& operator+=(int daynum);
    	//allows number-of-days to be added to the date object
    	sdate& operator-=(int daynum);
    	//allows number-of-days to be subtracted from the date object
    	void set_d_in_m();
    	//set the number-of-days of the given month
    	//take care of month Feb in leap year
    	int check_leap();
    	//returns 1 if its a leap year
    	int valid();
    	//returns 1 if the date is valid
    	void show_long() const;
    	//displays given date in long format eg: March 21,2001
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
    	friend long operator-(const sdate& d1, const sdate& d2);
    	friend std::ostream& operator<<(std::ostream& os, const sdate& d);
    	friend std::istream& operator>>(std::istream& is, sdate& d);
    	~sdate() {};
    	//destructor
};

    sdate operator+(const sdate& d, int i);
    sdate operator+(int i, const sdate& d);
    sdate operator-(const sdate& d, int i);
    long operator-(const sdate& d1, const sdate& d2);
    //returns the difference between the 2 dates
    //returns -1 in case the first date is smaller than the other
    std::ostream& operator<<(std::ostream& _os,const sdate& _dt);
    //allows statement like "cout<<date1"
    std::istream& operator>>(std::istream& _is,sdate& _dt);
    //allows statement like "cin>>date1"

#endif // _SDATE_H

