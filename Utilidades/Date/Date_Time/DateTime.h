/******************************************************************************
  Date and time utilities for C/C++
  Copyright (c) 2001-2002.
  Written by M.K.Ho (hmk409@yahoo.com)

  Conditions of distribution and use:
    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.

  Description:
    This utilities is designed for date and time management in C/C++. The
	functions include calculation of Day of week, Leap year, Days elapsed from
	year 0000, Millisecond elapsed from 00:00:00:0000, Date time addition and
	subtraction and Difference between two date time. This utilities also
	support DATE data type. The purpose of these functions is to provide the
	efficient, precision, easy and powerful tools to manage date and time.

  Files:
    DateTime.h   - Date and time utility header file
    DateTime.cpp - Date and time utility core
******************************************************************************/
#ifndef __DATETIME_H__
#define __DATETIME_H__

#pragma comment ( lib, "DateTime.lib" )

/* type definition ***********************************************************/
#ifdef WIN32

#include <wtypes.h>

#else

#ifndef BOOL
typedef int BOOL;
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

// see MSDN, DATE type, implementation
#ifndef DATE
typedef double DATE;
#endif

#endif

#ifndef Int16
typedef short Int16;
#endif

#ifndef UInt16
typedef unsigned short UInt16;
#endif

#ifndef Int32
typedef int Int32;
#endif

enum DT_MonthEnum
{	DTM_January = 0,
	DTM_Febrary = 1,
	DTM_March = 2,
	DTM_April = 3,
	DTM_May = 4,
	DTM_June = 5,
	DTM_July = 6,
	DTM_August = 7,
	DTM_September = 8,
	DTM_October = 9,
	DTM_November = 10,
	DTM_December = 11,

	DTM_JAN = 0,
	DTM_FEB = 1,
	DTM_MAR = 2,
	DTM_APR = 3,
	DTM_MAY = 4,
	DTM_JUN = 5,
	DTM_JUL = 6,
	DTM_AUG = 7,
	DTM_SEP = 8,
	DTM_OCT = 9,
	DTM_NOV = 10,
	DTM_DEC = 11,

	DTM_1 = 0,
	DTM_2 = 1,
	DTM_3 = 2,
	DTM_4 = 3,
	DTM_5 = 4,
	DTM_6 = 5,
	DTM_7 = 6,
	DTM_8 = 7,
	DTM_9 = 8,
	DTM_10 = 9,
	DTM_11 = 10,
	DTM_12 = 11,
};

enum DT_DayOfWeekEnum
{	DTDOW_Sunday = 0,
	DTDOW_Monday = 1,
	DTDOW_Tuesday = 2,
	DTDOW_Wednesday = 3,
	DTDOW_Thusday = 4,
	DTDOW_Friday = 5,
	DTDOW_Saturday = 6,

	DTDOW_SUN = 0,
	DTDOW_MON = 1,
	DTDOW_TUE = 2,
	DTDOW_WED = 3,
	DTDOW_THU = 4,
	DTDOW_FRI = 5,
	DTDOW_SAT = 6,
};

typedef struct DT_TimeTag
{	Int16 millisecond;
	Int16 second;
	Int16 minute;
	Int16 hour;
} DT_Time;

typedef struct DT_DateTag
{	Int16 day;
	Int16 month;
	Int16 year;
} DT_Date;

typedef struct DT_DateTimeTag
{	DT_Time time;
	DT_Date date;
} DT_DateTime;

typedef struct DT_SpanTag
{	UInt16 millisecond;
	UInt16 second;
	UInt16 minute;
	UInt16 hour;
	UInt16 day;
	UInt16 month;
	UInt16 year;
} DT_Span;

typedef Int32 DT_Days;
typedef Int32 DT_MS;

/* functions *****************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

#define dt_is_leap_year(y)	((((y)%400)==0)||((((y)%4)==0)&&(((y)%100)!=0)))

DT_DayOfWeekEnum dt_day_of_week ( Int16 y, Int16 m, Int16 d );

DT_Days dt_days_in_month ( Int16 y, Int16 m );
DT_Days dt_days_in_year ( Int16 y );
DT_Days dt_days_elapse_date ( Int16 y, Int16 m, Int16 d );
DT_Days dt_days_elapse_month ( Int16 y, Int16 m );
DT_Days dt_days_elapse_year ( Int16 y );
DT_Days dt_days_diff ( const DT_Date *to, const DT_Date *from );
void dt_days_to_date ( DT_Days days, DT_Date *date );

DT_MS dt_ms_elapse_time ( Int16 h, Int16 m, Int16 s, Int16 ms );
DT_MS dt_ms_diff ( const DT_Time *to, const DT_Time *from );
void dt_ms_to_time ( DT_MS ms, DT_Time *time );

void dt_GetLocal ( DT_DateTime *dt );
void dt_GetUTC ( DT_DateTime *dt );
#ifdef WIN32
void dt_SetLocal ( const DT_DateTime *dt );
void dt_SetUTC ( const DT_DateTime *dt );
#endif

BOOL dt_valid_date ( const DT_Date *date );
BOOL dt_valid_time ( const DT_Time *time );

Int32 dt_compare ( const DT_DateTime *dt1, const DT_DateTime *dt2 );
void dt_add ( DT_DateTime *dt, const DT_Span *span );
// 0 - 3 days error after dt_sub
#define dt_sub_max_days_error	3
void dt_sub ( DT_DateTime *dt, const DT_Span *span );

Int32 dt_date_compare ( const DT_Date *d1, const DT_Date *d2 );
Int32 dt_time_compare ( const DT_Time *t1, const DT_Time *t2 );

void dt_days_ms_adjust ( DT_Days *days, DT_MS *ms );
Int32 dt_days_ms_compare ( DT_Days days1, DT_MS ms1, DT_Days days2, DT_MS ms2 );

void dt_from_DATE ( DT_DateTime *dt, DATE date );
DATE dt_to_DATE ( const DT_DateTime *dt );

#if defined(__cplusplus)
}
#endif

/* class *********************************************************************/

#if defined(__cplusplus)

class DTC_DateTime : public DT_DateTimeTag
{
public:
	DTC_DateTime (void);
	DTC_DateTime ( const DT_DateTime &dt );
	DTC_DateTime ( const DT_Date &_date );
	DTC_DateTime ( const DT_Time &_time );
	DTC_DateTime ( DT_Days days, DT_MS ms );
	DTC_DateTime ( DATE _date );
	~DTC_DateTime (void);
public:
	void GetLocal (void);
	void GetUTC (void);
#ifdef WIN32
	void SetLocal (void);
	void SetUTC (void);
#endif

	void SetTo ( const DT_DateTime &dt );
	void SetTo ( const DT_Date &_date );
	void SetTo ( const DT_Time &_time );
	void SetTo ( DATE _date );

	DT_DayOfWeekEnum DayOfWeek (void) const;

	//void Adjust (void);
	void Add ( const DT_Span &span );
	void Sub ( const DT_Span &span );
	BOOL CompareTo ( const DT_DateTime &dt ) const;

	DT_Days GetDays (void) const;
	DT_MS GetMS (void) const;
	DATE GetDATE (void) const;

	DT_DateTime &operator = ( const DT_DateTime &dt );
	DT_DateTime &operator = ( const DT_Date &_date );
	DT_DateTime &operator = ( const DT_Time &_time );
	DT_DateTime &operator = ( DATE _date );
	void operator += ( const DT_Span &span );
	void operator -= ( const DT_Span &span );
	BOOL operator < ( const DT_DateTime &dt ) const;
	BOOL operator <= ( const DT_DateTime &dt ) const;
	BOOL operator == ( const DT_DateTime &dt ) const;
	BOOL operator != ( const DT_DateTime &dt ) const;
	BOOL operator >= ( const DT_DateTime &dt ) const;
	BOOL operator > ( const DT_DateTime &dt ) const;
	operator DATE (void) const;
};

inline DTC_DateTime::DTC_DateTime (void)
{
}

inline DTC_DateTime::DTC_DateTime ( const DT_DateTime &dt )
{	SetTo ( dt );
}

inline DTC_DateTime::DTC_DateTime ( const DT_Date &_date )
{	SetTo ( _date );
}

inline DTC_DateTime::DTC_DateTime ( const DT_Time &_time )
{	SetTo ( _time );
}

inline DTC_DateTime::DTC_DateTime ( DT_Days days, DT_MS ms )
{	dt_days_to_date ( days, &date );
	dt_ms_to_time ( ms, &time );
}

inline DTC_DateTime::DTC_DateTime ( DATE _date )
{	SetTo ( _date );
}

inline DTC_DateTime::~DTC_DateTime (void)
{
}

inline void DTC_DateTime::GetLocal (void)
{	dt_GetLocal ( this );
}

inline void DTC_DateTime::GetUTC (void)
{	dt_GetUTC ( this );
}

#ifdef WIN32
inline void DTC_DateTime::SetLocal (void)
{	dt_SetLocal ( this );
}

inline void DTC_DateTime::SetUTC (void)
{	dt_GetUTC ( this );
}
#endif

inline void DTC_DateTime::SetTo ( const DT_DateTime &dt )
{	*(DT_DateTime *)this = dt;
}

inline void DTC_DateTime::SetTo ( const DT_Date &_date )
{	date = _date;
	time.hour = time.minute = time.second = time.millisecond = 0;
}

inline void DTC_DateTime::SetTo ( const DT_Time &_time )
{	date.year = date.month = date.day = 0;
	time = _time;
}

inline void DTC_DateTime::SetTo ( DATE _date )
{	dt_from_DATE ( this, _date );
}

inline DT_DayOfWeekEnum DTC_DateTime::DayOfWeek (void) const
{	return dt_day_of_week ( date.year, date.month, date.day );
}

/*inline void DTC_DateTime::Adjust (void)
{	dt_adjust ( this );
}*/

inline void DTC_DateTime::Add ( const DT_Span &span )
{	dt_add ( this, &span );
}

inline void DTC_DateTime::Sub ( const DT_Span &span )
{	dt_sub ( this, &span );
}

inline BOOL DTC_DateTime::CompareTo ( const DT_DateTime &dt ) const
{	return dt_compare ( this, &dt );
}

inline DT_Days DTC_DateTime::GetDays (void) const
{	return dt_days_elapse_date ( date.year, date.month, date.day );
}

inline DT_MS DTC_DateTime::GetMS (void) const
{	return dt_ms_elapse_time ( time.hour, time.minute, time.second, time.millisecond );
}

inline DATE DTC_DateTime::GetDATE (void) const
{	return dt_to_DATE ( this );
}

inline DT_DateTime &DTC_DateTime::operator = ( const DT_DateTime &dt )
{	SetTo ( dt );
	return *this;
}

inline DT_DateTime &DTC_DateTime::operator = ( const DT_Date &_date )
{	SetTo ( _date );
	return *this;
}

inline DT_DateTime &DTC_DateTime::operator = ( const DT_Time &_time )
{	SetTo ( _time );
	return *this;
}

inline DT_DateTime &DTC_DateTime::operator = ( DATE _date )
{	SetTo ( _date );
	return *this;
}

inline void DTC_DateTime::operator += ( const DT_Span &span )
{	Add ( span );
}

inline void DTC_DateTime::operator -= ( const DT_Span &span )
{	Sub ( span );
}

inline BOOL DTC_DateTime::operator < ( const DT_DateTime &dt ) const
{	return CompareTo ( dt ) < 0;
}

inline BOOL DTC_DateTime::operator <= ( const DT_DateTime &dt ) const
{	return CompareTo ( dt ) <= 0;
}

inline BOOL DTC_DateTime::operator == ( const DT_DateTime &dt ) const
{	return CompareTo ( dt ) == 0;
}

inline BOOL DTC_DateTime::operator != ( const DT_DateTime &dt ) const
{	return CompareTo ( dt ) != 0;
}

inline BOOL DTC_DateTime::operator >= ( const DT_DateTime &dt ) const
{	return CompareTo ( dt ) >= 0;
}

inline BOOL DTC_DateTime::operator > ( const DT_DateTime &dt ) const
{	return CompareTo ( dt ) > 0;
}

inline DTC_DateTime::operator DATE (void) const
{	return GetDATE ();
}

/*****************************************************************************/

class DTC_Date : public DT_DateTag
{
public:
	DTC_Date (void);
	DTC_Date ( const DT_Date &date );
	DTC_Date ( DT_Days days );
	~DTC_Date (void);
public:
	void SetTo ( const DT_Date &date );
	void SetTo ( DT_Days days );

	DT_DayOfWeekEnum DayOfWeek (void) const;

	BOOL CompareTo ( const DT_Date &date ) const;

	DT_Days GetDays (void) const;

	DT_Date &operator = ( const DT_Date &date );
	DT_Date &operator = ( DT_Days days );
	BOOL operator < ( const DT_Date &date ) const;
	BOOL operator <= ( const DT_Date &date ) const;
	BOOL operator == ( const DT_Date &date ) const;
	BOOL operator != ( const DT_Date &date ) const;
	BOOL operator >= ( const DT_Date &date ) const;
	BOOL operator > ( const DT_Date &date ) const;
	operator DT_Days (void) const;
};

inline DTC_Date::DTC_Date (void)
{
}

inline DTC_Date::DTC_Date ( const DT_Date &date )
{	SetTo ( date );
}

inline DTC_Date::DTC_Date ( DT_Days days )
{	SetTo ( days );
}

inline DTC_Date::~DTC_Date (void)
{
}

inline void DTC_Date::SetTo ( const DT_Date &date )
{	*(DT_Date *)this = date;
}

inline void DTC_Date::SetTo ( DT_Days days )
{	dt_days_to_date ( days, this );
}

inline DT_DayOfWeekEnum DTC_Date::DayOfWeek (void) const
{	return dt_day_of_week ( year, month, day );
}

inline BOOL DTC_Date::CompareTo ( const DT_Date &date ) const
{	return dt_date_compare ( this, &date );
}

inline DT_Days DTC_Date::GetDays (void) const
{	return dt_days_elapse_date ( year, month, day );
}

inline DT_Date &DTC_Date::operator = ( const DT_Date &date )
{	SetTo ( date );
	return *this;
}

inline DT_Date &DTC_Date::operator = ( DT_Days days )
{	SetTo ( days );
	return *this;
}

inline BOOL DTC_Date::operator < ( const DT_Date &date ) const
{	return CompareTo ( date ) < 0;
}

inline BOOL DTC_Date::operator <= ( const DT_Date &date ) const
{	return CompareTo ( date ) <= 0;
}

inline BOOL DTC_Date::operator == ( const DT_Date &date ) const
{	return CompareTo ( date ) == 0;
}

inline BOOL DTC_Date::operator != ( const DT_Date &date ) const
{	return CompareTo ( date ) != 0;
}

inline BOOL DTC_Date::operator >= ( const DT_Date &date ) const
{	return CompareTo ( date ) >= 0;
}

inline BOOL DTC_Date::operator > ( const DT_Date &date ) const
{	return CompareTo ( date ) > 0;
}

inline DTC_Date::operator DT_Days (void) const
{	return GetDays ();
}

/*****************************************************************************/

class DTC_Time : public DT_TimeTag
{
public:
	DTC_Time (void);
	DTC_Time ( const DT_Time &time );
	DTC_Time ( DT_MS ms );
	~DTC_Time (void);
public:
	void SetTo ( const DT_Time &time );
	void SetTo ( DT_MS ms );

	BOOL CompareTo ( const DT_Time &time ) const;

	DT_MS GetMS (void) const;

	DT_Time &operator = ( const DT_Time &time );
	DT_Time &operator = ( DT_MS ms );
	BOOL operator < ( const DT_Time &time ) const;
	BOOL operator <= ( const DT_Time &time ) const;
	BOOL operator == ( const DT_Time &time ) const;
	BOOL operator != ( const DT_Time &time ) const;
	BOOL operator >= ( const DT_Time &time ) const;
	BOOL operator > ( const DT_Time &time ) const;
	operator DT_MS (void) const;
};

inline DTC_Time::DTC_Time (void)
{
}

inline DTC_Time::DTC_Time ( const DT_Time &time )
{	SetTo ( time );
}

inline DTC_Time::DTC_Time ( DT_MS ms )
{	SetTo ( ms );
}

inline DTC_Time::~DTC_Time (void)
{
}

inline void DTC_Time::SetTo ( const DT_Time &time )
{	*(DT_Time *)this = time;
}

inline void DTC_Time::SetTo ( DT_MS ms )
{	dt_ms_to_time ( ms, this );
}

inline BOOL DTC_Time::CompareTo ( const DT_Time &time ) const
{	return dt_time_compare ( this, &time );
}

inline DT_MS DTC_Time::GetMS (void) const
{	return dt_ms_elapse_time ( hour, minute, second, millisecond );
}

inline DT_Time &DTC_Time::operator = ( const DT_Time &time )
{	SetTo ( time );
	return *this;
}

inline DT_Time &DTC_Time::operator = ( DT_MS ms )
{	SetTo ( ms );
	return *this;
}

inline BOOL DTC_Time::operator < ( const DT_Time &time ) const
{	return CompareTo ( time ) < 0;
}

inline BOOL DTC_Time::operator <= ( const DT_Time &time ) const
{	return CompareTo ( time ) <= 0;
}

inline BOOL DTC_Time::operator == ( const DT_Time &time ) const
{	return CompareTo ( time ) == 0;
}

inline BOOL DTC_Time::operator != ( const DT_Time &time ) const
{	return CompareTo ( time ) != 0;
}

inline BOOL DTC_Time::operator >= ( const DT_Time &time ) const
{	return CompareTo ( time ) >= 0;
}

inline BOOL DTC_Time::operator > ( const DT_Time &time ) const
{	return CompareTo ( time ) > 0;
}

inline DTC_Time::operator DT_MS (void) const
{	return GetMS ();
}

/*****************************************************************************/

inline DT_Days operator - ( const DTC_Date &to, const DTC_Date &from )
{	return dt_days_diff ( &to, &from );
}

inline DT_MS operator - ( const DTC_Time &to, const DTC_Time &from )
{	return dt_ms_diff ( &to, &from );
}

#endif

#endif
