#include "sdate.h"

char meses[][13] = {" ", "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez" };

/*
int main() {
    sdate d1(29, 2, 05);
    if(d1.valid())
	cout << "valido" << endl;
    else
	cout << "invalido" << endl;
	
    cout << d1++ << endl;
    cout << d1++ << endl;
    cout << d1 << endl;
    
    cout << d1.get_day() << endl;
    cout << d1.get_month() << endl;
    cout << d1.get_year() << endl;
    
    d1.show_long();
    return 0;
}
*/

sdate::sdate()
{
    struct tm *system_data;
    time_t data;
    data = time(NULL);
    system_data = localtime(&data);
    
    day   = system_data->tm_mday;
    month = system_data->tm_mon + 1;
    year  = system_data->tm_year + 1900;
    set_d_in_m();
};

///////////////////////////////////////////////////////////////////////////////////////
sdate :: sdate(int dd, int mm, int yy)


    {	day=dd; month=mm; year=yy;
    	set_d_in_m();
}
///////////////////////////////////////////////////////////////////////////////////////
int sdate :: valid()


    {cout<<days_in_month<<endl;
    	if((month<1) || (month>12) || (day<1) || (day>days_in_month))
    	{ cout<<" Invalid Date! \n"; return 0;}
    	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////
void sdate :: set_d_in_m()


    {	int i=month%2;
    	if((month<8 && i==0) || (month>7 && i==1)) days_in_month=30;
    	else days_in_month=31;
    	if(month==2)
    	{ if(check_leap()) days_in_month=29;
    	else days_in_month=28;
    	};
}
///////////////////////////////////////////////////////////////////////////////////////
char* sdate :: mname(int month) const


    {	char *p=NULL;
    	switch(month)


        	{
        		case 1: p = "January";	 break;
        		case 2: p = "February"; break;
        		case 3: p = "March";break;
        		case 4: p = "April";break;
        		case 5: p = "May";break;
        		case 6: p = "June";break;
        		case 7: p = "July";break;
        		case 8: p = "August"; break;
        		case 9: p = "September"; break;
        		case 10: p = "October";	 break;
        		case 11: p = "November"; break;
        		case 12: p = "December"; break;
        	}
        	return p;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int sdate :: check_leap()


        {	if(year%4!=0) return 0;
        	else if(year%100!=0) return 1;
        	else if(year%400!=0) return 0;
        	else return 1;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    void sdate :: show_long() const


        {	char* monthname = mname(month);
        	cout<<" ";
        	while(*monthname!=NULL)
        		{ cout<<*monthname; monthname++;}
        	cout<<" "<<day<<","<<year<<" ";
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    ostream& operator<<(ostream& os, const sdate& d)


        {	os<<" "<<d.day<<"/"<<d.month<<"/"<<d.year<<" ";
        	return os;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    istream& operator>>(istream& is, sdate& d)


        {	do
        	{ 	cout<<endl<<" Day: "; is>>d.day;
        		cout<<" Month: "; is>>d.month;
        		cout<<" Year: "; is>>d.year;
        		d.set_d_in_m();
        	}
        	while(!d.valid());
        	return is;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    sdate :: sdate(const sdate& d)


        {	year=d.year; month=d.month;
        	day=d.day; days_in_month=d.days_in_month;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    sdate& sdate :: operator=(const sdate& d)


        {	year=d.year; month=d.month;	day=d.day;
        	days_in_month=d.days_in_month;
        	return *this;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int sdate :: operator==(const sdate& d) const


        {	if((year==d.year)&&(month==d.month)&&(day==d.day))
        	return 1;
        	else return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int sdate :: operator!=(const sdate& d) const


        {	return !(*this==d);
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int sdate :: operator<(const sdate& d) const


        {	if(year<d.year) return 1;
        	else if(year==d.year)
        	{	if(month<d.month) return 1;
        		else if(month==d.month)
        		{	if(day<d.day) return 1; }
        	}
        	return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    int sdate :: operator>(const sdate& d) const


        {
        	return (d < (*this));
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    sdate& sdate :: operator+=(int daynum)


        {if(daynum>=0)


            	{
            	day += daynum;
            	while(day>days_in_month)
            		{ day -= days_in_month;
            		 if(month!=12) month++;
            		 else {year++; month=1;}
            		 set_d_in_m();
            		}
            	return *this;
            	}
            	else return (*this)-=(-daynum);
        }
        ///////////////////////////////////////////////////////////////////////////////////////
        sdate& sdate :: operator++()


            {	(*this)+=1;
            	return *this;
        }
        ///////////////////////////////////////////////////////////////////////////////////////
        sdate sdate :: operator++(int)


            {sdate temp = *this;
            	(*this)+=1;
            	return temp;
        }
        ///////////////////////////////////////////////////////////////////////////////////////
        sdate& sdate :: operator-=(int daynum)


            {if(daynum>=0)


                	{
                	day -= daynum;
                	while(day<=0)
                		{ if(month!=1) month--;
                		 else {year--; month=12;}
                		 set_d_in_m();
                		 day += days_in_month;
                		}
                	return *this;
                	}
                	else return (*this)+=(-daynum);
            }
            ///////////////////////////////////////////////////////////////////////////////////////
            sdate& sdate :: operator--()


                {	(*this)-=1;
                	return *this;
            }
            ///////////////////////////////////////////////////////////////////////////////////////
            sdate sdate :: operator--(int)


                {sdate temp = *this;
                	(*this)-=1;
                	return temp;
            }
            ///////////////////////////////////////////////////////////////////////////////////////
            sdate operator+(const sdate& d1, int i)


                {	sdate temp=d1; 	temp+=i;
                	return temp;
            }
            ///////////////////////////////////////////////////////////////////////////////////////
            sdate operator+(int i, const sdate& d)


                {	return d+i;
            }
            ///////////////////////////////////////////////////////////////////////////////////////
            long operator-(const sdate& d1, const sdate& d2)


                {	long diff=0;
                	if(d1==d2) return diff;
                	if(d1<d2) return -1;


                    	else{
                    	if((d1.year==d2.year) && (d1.month==d2.month))
                    		diff = d1.day - d2.day;
                    	else
                    	{	diff=d1.day;
                    		sdate temp=d1;
                    		if(temp.month==1)
                    		{ temp.year--; temp.month=12;}
                    		else temp.month--;
                    		while((temp.year!=d2.year) || (temp.month!=d2.month))
                    		{ temp.set_d_in_m();
                    			diff+=temp.days_in_month;
                    			if(temp.month==1)
                    			{ temp.year--; temp.month=12;}
                    			else temp.month--;
                    		};
                    		diff+=d2.days_in_month-d2.day;
                    	}
                    	return diff;
                    	}
                }
                ///////////////////////////////////////////////////////////////////////////////////////
                sdate operator-(const sdate& d1, int i)


                    {	sdate temp=d1; 	temp-=i;
                    	return temp;
                }
                ///////////////////////////////////////////////////////////////////////////////////////
		


