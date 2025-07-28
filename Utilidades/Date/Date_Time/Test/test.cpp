#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "..\datetime.h"

#define SHOW_DATA
#define SELF_TEST

void ShowCalender ( int year, int month )
{	int dow;
	int days;
	int i;

	dow = dt_day_of_week ( year, month, 0 );
	days = dt_days_in_month ( year, month );

	printf ( "%d-%02d\n", year, month+1 );
	printf ( " S  M  T  W  T  F  S\n" );
	printf ( "---------------------\n" );
	for ( i = 0; i < dow; i++ )
		printf ( "   " );

	for ( i = 0; i < days; i++ )
	{	printf ( "%2d ", i+1 );
		if ( dow++ == DTDOW_Saturday )
		{	printf ( "\n" );
			dow = DTDOW_Sunday;
		}
	}
	printf ( "\n\n" );
}

void ShowDate ( DT_DateTime *dt )
{	printf ( "%d-%02d-%02d %02d:%02d:%02d:%04d ",
			dt->date.year, dt->date.month+1, dt->date.day+1,
			dt->time.hour, dt->time.minute, dt->time.second, dt->time.millisecond );

	if ( dt_is_leap_year ( dt->date.year ) )
		printf ( "leap year\n" );
	else
		printf ( "not a leap year\n" );
}

void main (void)
{	DT_DateTime now, dt;
	DT_Span span;
	DT_Days days[2];
	DT_MS ms[2];
	DATE date;
	int i, err;

	srand( (unsigned)time( NULL ) );


#ifdef SHOW_DATA
	dt_GetLocal ( &now );
	ShowDate ( &now );
	days[0] = dt_days_elapse_date ( now.date.year, now.date.month, now.date.day );
	ms[0] = dt_ms_elapse_time ( now.time.hour, now.time.minute, now.time.second, now.time.millisecond );
	printf ( "%ld days %ld ms elapsed from 0000/1/1 00:00:00:0000\n", days[0], ms[0] );
	//printf ( "%ld days elapsed from 0000\n", dt_days_elapse_date ( 0000, DTM_JAN, 0 ) );
	dt_days_to_date ( days[0], &dt.date );
	dt_ms_to_time ( ms[0], &dt.time );
	ShowDate ( &dt );
	printf ( "\n" );

	dt = now;
	ShowCalender ( dt.date.year, dt.date.month );
	//ShowCalender ( 2000, DTM_January );

	printf ( "month              : " );
	for ( i = 0; i < 12; i++ )
		printf ( "%3d ", i+1 );
	printf ( "\n" );
	printf ( "total days in month: " );
	for ( i = 0; i < 12; i++ )
		printf ( "%3d ", dt_days_in_month ( now.date.year, i ) );
	printf ( "\n" );
	printf ( "days elapse month  : " );
	for ( i = 0; i < 12; i++ )
		printf ( "%3d ", dt_days_elapse_month ( now.date.year, i ) );
	printf ( "\n" );
	printf ( "total days in year = %ld\n\n", dt_days_in_year ( now.date.year ) );

printf ( "year\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.year = 10;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );

printf ( "month\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.month = 18;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );

printf ( "day\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.day = 365;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );

printf ( "hour\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.hour = 10;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );

printf ( "minute\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.minute = 43;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );

printf ( "second\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.second = 131;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );

printf ( "millisecond\n" );
	memset ( &span, 0, sizeof(span) );
	dt = now;
	span.millisecond = 511;
	ShowDate ( &dt );
	dt_add ( &dt, &span );
	days[0] = dt_days_diff ( &dt.date, &now.date );
	days[1] = dt_days_diff ( &now.date, &dt.date );
	ms[0] = dt_ms_diff ( &dt.time, &now.time );
	ms[1] = dt_ms_diff ( &now.time, &dt.time );
	dt_days_ms_adjust ( &days[0], &ms[0] );
	dt_days_ms_adjust ( &days[1], &ms[1] );
	ShowDate ( &dt );
	printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
	printf ( "%ld days %ld ms difference\n", days[1], ms[1] );
	printf ( "\n" );
#endif


#ifdef SELF_TEST
printf ( "Self test\n" );

	// see MSDN, DATE type, implementation
	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 30-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	date = dt_to_DATE ( &dt );
	if ( date != 0.00 )
		printf ( "DATE error, 30 December 1899, midnight => 0.00 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 1-1;
	dt.date.month = DTM_January;
	dt.date.year = 1900;
	date = dt_to_DATE ( &dt );
	if ( date != 2.00 )
		printf ( "DATE error, 1 January 1900, midnight => 2.00 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 4-1;
	dt.date.month = DTM_January;
	dt.date.year = 1900;
	date = dt_to_DATE ( &dt );
	if ( date != 5.00 )
		printf ( "DATE error, 4 January 1900, midnight => 5.00 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 4-1;
	dt.date.month = DTM_January;
	dt.date.year = 1900;
	dt.time.hour = 6;
	date = dt_to_DATE ( &dt );
	if ( date != 5.25 )
		printf ( "DATE error, 4 January 1900, 6 A.M. => 5.25 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 4-1;
	dt.date.month = DTM_January;
	dt.date.year = 1900;
	dt.time.hour = 12;
	date = dt_to_DATE ( &dt );
	if ( date != 5.50 )
		printf ( "DATE error, 4 January 1900, noon => 5.50 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 4-1;
	dt.date.month = DTM_January;
	dt.date.year = 1900;
	dt.time.hour = 12+9;
	date = dt_to_DATE ( &dt );
	if ( date != 5.875 )
		printf ( "DATE error, 4 January 1900, 9 P.M. => 5.875 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 29-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	date = dt_to_DATE ( &dt );
	if ( date != -1.00 )
		printf ( "DATE error, 29 December 1899, midnight => -1.00 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 18-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	date = dt_to_DATE ( &dt );
	if ( date != -12.00 )
		printf ( "DATE error, 18 December 1899, midnight => -12.00 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}

	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 18-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	dt.time.hour = 6;
	date = dt_to_DATE ( &dt );
	if ( date != -12.25 )
		printf ( "DATE error, 18 December 1899, 6 A.M. => -12.25 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}
 
	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 18-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	dt.time.hour = 12;
	date = dt_to_DATE ( &dt );
	if ( date != -12.50 )
		printf ( "DATE error, 18 December 1899, noon => -12.50 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}
 
	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 18-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	dt.time.hour = 12+6;
	date = dt_to_DATE ( &dt );
	if ( date != -12.75 )
		printf ( "DATE error, 18 December 1899, 6 P.M. => -12.75 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}
 
	memset ( &dt, 0, sizeof(dt) );
	dt.date.day = 19-1;
	dt.date.month = DTM_December;
	dt.date.year = 1899;
	date = dt_to_DATE ( &dt );
	if ( date != -11.00 )
		printf ( "DATE error, 19 December 1899, midnight => -11.00 != %lf\n", date );
	dt_from_DATE ( &now, date );
	if ( dt_compare ( &now, &dt ) != 0 )
	{	ShowDate ( &dt );
		ShowDate ( &now );
	}


	err = 0;
	for ( i = 0; i < 100000; i++ )
	{	now.date.year = rand () % 3000;
		now.date.month = rand () % 12;
		now.date.day = rand () % dt_days_in_month ( now.date.year, now.date.month );
		now.time.hour = rand () % 24;
		now.time.minute = rand () % 60;
		now.time.second = rand () % 60;
		now.time.millisecond = rand () % 1000;
		
		span.year = rand () % 50;
		span.month = rand () % 24;
		span.day = rand () % 90;
		span.hour = rand () % 36;
		span.minute = rand () % 120;
		span.second = rand () % 300;
		span.millisecond = rand ();

		/*now.date.year = 1926;
		now.date.month = 7;
		now.date.day = 30;
		now.time.hour = 1;
		now.time.minute = 1;
		now.time.second = 5;
		now.time.millisecond = 47;
		span.year = 39;
		span.month = 8;
		span.day = 55;
		span.hour = 12;
		span.minute = 52;
		span.second = 20;
		span.millisecond = 19459;*/

		days[0] = dt_days_elapse_date ( now.date.year, now.date.month, now.date.day );
		ms[0] = dt_ms_elapse_time ( now.time.hour, now.time.minute, now.time.second, now.time.millisecond );

		dt_days_to_date ( days[0], &dt.date );
		dt_ms_to_time ( ms[0], &dt.time );

		if ( dt_compare ( &now, &dt ) != 0 )
		{	printf ( "Conversion error, date <=> days, time <=> ms\n" );
			ShowDate ( &now );
			printf ( "%ld days %ld ms elapsed\n", days[0], ms[0] );
			ShowDate ( &dt );
			err++;
		}

		dt = now;
		dt_add ( &dt, &span );
		days[0] = dt_days_diff ( &dt.date, &now.date );
		days[1] = dt_days_diff ( &now.date, &dt.date );
		ms[0] = dt_ms_diff ( &dt.time, &now.time );
		ms[1] = dt_ms_diff ( &now.time, &dt.time );
		dt_days_ms_adjust ( &days[0], &ms[0] );
		dt_days_ms_adjust ( &days[1], &ms[1] );

		if ( days[0] != -days[1] || ms[0] != -ms[1] )
		{	printf ( "Diff error\n" );
			ShowDate ( &now );
			ShowDate ( &dt );
			printf ( "%ld days %ld ms difference\n", days[0], ms[0] );
			printf ( "%ld days %ld ms difference\n", days[1], ms[1] );
			err++;
		}

		dt_sub ( &dt, &span );
		if ( !dt_valid_date ( &dt.date ) )
		{	printf ( "sub error - invalid date\n" );
			ShowDate ( &dt );
			err++;
		}
		if ( dt_compare ( &now, &dt ) != 0 )
		{	//printf ( "sub error\n" );
			//ShowDate ( &now );
			//ShowDate ( &dt );
			days[0] = dt_days_elapse_date ( now.date.year, now.date.month, now.date.day );
			days[1] = dt_days_elapse_date ( dt.date.year, dt.date.month, dt.date.day );
			if ( days[1] - days[0] > dt_sub_max_days_error )
			{	printf ( "over error limit: %d days different\n", days[1] - days[0] );
				err++;
			}
			dt_add ( &now, &span );
			dt_add ( &dt, &span );
			if ( dt_compare ( &now, &dt ) != 0 )
			{	printf ( "can't meet at future\n" );
				err++;
			}
		}

		span.year = 0;
		span.month = 0;
		span.day = rand () % 1000;
		span.hour = 0;
		span.minute = 0;
		span.second = 0;
		span.millisecond = 0;

		days[0] = dt_days_elapse_date ( now.date.year, now.date.month, now.date.day );
		dt_add ( &now, &span );
		days[0] += span.day;
		dt_days_to_date ( days[0], &dt.date );
		dt.time = now.time;
		if ( dt_date_compare ( &now.date, &dt.date ) != 0 )
		{	printf ( "add date/day error: add %d days\n", span.day );
			ShowDate ( &now );
			ShowDate ( &dt );
			err++;
		}

		if ( err > 5 )
			break;
	}

#if defined(__cplusplus)
	{	DTC_DateTime xxx[] = { DTC_DateTime ( now ), DTC_DateTime ( dt ) };

		xxx[0] += span;
		xxx[0] -= span;
		xxx[0] = xxx[1] = now;
	}
	{	DTC_Date xxx[] = { DTC_Date ( now.date ), DTC_Date ( dt.date ) };

		xxx[0] = 287429;
		xxx[0] = xxx[1] = now.date;
	}
	{	DTC_Time xxx[] = { DTC_Time ( now.time ), DTC_Time ( dt.time ) };

		xxx[0] = 28742934;
		xxx[0] = xxx[1] = now.time;
	}
#endif

	if ( err )
		printf ( "Too many error\n\n" );
	else
		printf ( "No error found\n\n" );
#endif
}

