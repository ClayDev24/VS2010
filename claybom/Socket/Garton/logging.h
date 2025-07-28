/////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************
	
	Name der Datei:	logging.h
	Zweck:			Fehler in eine Textdatei schreiben
	Autoren:		Bastian Rieck, Helmut Erlenkötter
	
********************************************************/
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef H_LOGGING
#define H_LOGGING

//INCLUDES////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <windows.h>
#include <windowsx.h> 
#include <mmsystem.h>
#include <iostream.h>	//WICHTIGE DINGE FÜR C/C++
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#include <io.h>
#include <fcntl.h>
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/******************************************************************************

	Funktion: exists
	Aufruf: exists(char *file)
	Parameter: file = Zeiger auf die Datei
	Rückgabewert: true/false
	Zweck: Überprüft, ob eine Datei existiert, oder nicht
	
********************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////
bool exists(char *file)
{	//BEGINN DER FUNKTION exists
	
	FILE *stream;	//ZEIGER AUF DIE DATEI

	stream = fopen(file, "r");	//NUR-LESEN MODUS EINGESCHALTET

	if (stream != NULL)	//DIE DATEI EXISTIERT, DAS HEISST ES WIRD TRUE ZTURÜCKGEGEBEN
	{	//ANFANG IF
		
		fclose(stream);	//DATEI SCHLIESSEN
		return true;	//TRUE ZURÜCKGEBEN

	}	//ENDE IF

	else	//DIE DATEI EXISTIERT NICHT
	{	//ANFANG ELSE
		
		fclose(stream);	//DATEI SCHLIESSEN
		return false;	//FALSE ZURÜCKGEBEN

	}	//ENDE ELSE

}	//ENDE DER FUNKTION exists
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
/*************************************************************************
	
	Funktion: logData
	Aufruf(logData(char *message)
	Parameter: message = die Nachricht, die geloggt werden soll
	Rückgabewert: Keiner
	Zweck: Schreibt die übergebene Nachricht in die Datei "log.log"
	
**************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////
void logData(char *message, char *FileToLog = "log.log")
{	//BEGINN DER FUNKTION logData
	
	FILE *LogFile;	//ZEIGER AUF DIE DATEI

	if (!exists(FileToLog))	//EXISTIERT DIE DATEI?
		LogFile = fopen(FileToLog, "w");	//NEIN, NEU ANLEGEN UND BESCHREIBEN
	
	else					//SIE EXISTIERT DOCH
		LogFile = fopen(FileToLog, "a");	//ANHÄNGEN AN BESTEHENDE MELDUNGEN


	if (strlen(message) > 0)	//IST DIE LÄNGE DER NACHRICHT GRÖSSER NULL, SO WIRD GEXCHRIEBEN
		fprintf(LogFile, "%s\n", message);	//EINFÜGEN DER NACHRICHT IN DIE DATEI
	

	fclose(LogFile);	//SCHLIESSEN DER DATEI

}	//ENDE DER FUNKTION logData
/////////////////////////////////////////////////////////////////////////////////////////

#endif