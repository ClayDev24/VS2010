/*
		Programm:	Garton 1.7 - Ein kleiner Telnetersatz
		Autor:		Bastian Rieck
		Datum:		15.06.2001

		WICHTIG:
					Zum Linken in den Compileroptionen Multithreading angeben und 
					folgende Dateien mitlinken:
					- winsock.dll
					- ws2_32.lib
					- libcmt.lib

*/


// ---------------------------------------------------------------------------

// Includes
#include <windows.h>	// Die Win32-API
#include <stdio.h>      // Standard I/O Unterstützung  
#include <string.h>     // Zum Umgang mit Strings  
#include <memory.h>		// Speicherverwaltung, Reservierung etc.
#include <process.h>	// Multithreading
#include <conio.h>		// Standardausgabe mit printf
#include <io.h>			// Wieder I/O Unterstützung
#include <iostream.h>	// cin <--> cout
#include <winsock.h>	// Wir schreiben ja ein Programm mit Sockets, oder?
#include <winbase.h>	// Das ist für die Eingabe/Ausgabe (mal wieder)

#include "wsock.h"		// Eine eigene Datei mit Spezifikationen
#include "search.h"		// Eine eigene Datei mit einer 
						// genialen Suchfunktion
#include "logging.h"	// Erweiterte Log-Funktionen

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

// Makros & Defines

// Überprüft, ob eine Taste gedrückt wurde
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

// Maximale Anzahl der Zeichen
#define MAXIMAL_CHARS_IN_FILES			201				// 200 Zeichen

// Name der INI-Datei
#define	NAME_OF_INIFILE					"garton.ini"	// Das ist der Name der Configdatei

// Anzahl der benutzten Funktionstasten
#define NUMBER_OF_USED_FUNCTION_KEYS	2				// 2 Tasten, denn wir wollen ja keine Platz verschwenden.

// Dies sind die Werte der Statusnachrichten
#define STATUS_MSG_CONNECT				0				// 0 = Verbindung
#define STATUS_MSG_DISCONNECT			1				// 1 = Fehler, disconnect


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

// Globale Variablen

/********************************************************************
	Hinweis:
	In diesem Programm sind alle wichtigen Variablen global, da
	dies die Programmierung spezifischer Funktionen einfacher macht.
*********************************************************************/


SOCKET SocketData;					// Struktur für die Daten des Sockets
WSADATA WinsockData;				// Variable für die Daten von Winsock

struct hostent *host_info;			// Struktur für die Daten des Hosts
struct sockaddr_in TargetAddress;	// Die Adresse, zu der sich der Client verbindet

int nError = 0;						// Die Variable für Fehler 
int nSocket = 0;					// Die Variable zur Socketerstellung
int nCount = 0;						// Die Variable zum Empfang von Daten
int nExit = 1;						// Zum Beenden
int nFindDuplicates = 1;			// Sollen Duplikate gesucht werden?
int nLogging = 1;					// Sollen die Daten geloggt werden?

unsigned long nRead = 0;			// Variable zum Senden der Daten

short wVersionRequested;			// Die Variable zum Starten von Winsock

bool bConnected = false;			// Steht gerade eine Verbindung?

HANDLE hInput = NULL;				// Handle für die Eingabe

char cMsg[512] = { 0 };				// Die Nachricht, die versendet wird
char cData[512] = { 0 };			// Die Daten, die ankommen
char cGlobalBuffer[512] = { 0 };	// Der globale Puffer
char cParameter_1[MAXIMAL_CHARS];	// Der erste Parameter
char cParameter_2[MAXIMAL_CHARS];	// Der zweite	
char cParameter_3[MAXIMAL_CHARS];	// Der dritte
char cKommando[51] = { 0 };			// Und das Kommando
char cFunktionstasten[3][81];		// Die gesamten Funktionstasten
char cStatusMsg[5][500];			// Ein Feld für die Meldungen


// Globale Funktionsdefinition
void HandleInput(char[8192]);


// Die bisherigen Kommandos
char* Kommandos[]={"/connect",		// Ihr dürft raten
				   "/quit",			// Exit
				   "/ende",			// Exit
				   "/exit",			// Exit
				   "/info",			// NYI, sorry
				   "/hilfe",		// Anzeigen der Hilfedatei
				   "/help",			// Dito
				   "/disconnect"	// Verbindung trennen
				   };

// Die Konstanten für die Befehlsverarbeitung, in einem Enum gespeichert, nur zum  Spaß
enum
{	// Anfang Enum
	CONNECT = 1,
	QUIT,
	ENDE,
	EXIT,
	INFO,
	HILFE,
	HELP,
	DISCONNECT
};	// Ende Enum

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

/**************************************************************************
	Name der Funktion:	CheckKeys
	Parameter:			Keine
	Rückgabewert:		Keiner
	Zweck:				Dieser Thread überprüft, ob die Funktionstasten 
						gedrückt sind, und setzt dann die 
						spezifischen Ereignisse inkraft.
***************************************************************************/

void CheckKey(void *ptrDummy)
{	// Anfang der Funktion void CheckKey(void *ptrDummy)

	SHORT sKeyState;			// Status der Taste
	SHORT sArrKeyState[256];	// Gesamtes Feld der Tasten
	
	long lCheckSum;				// Checksumme der Tasten
	long lOldCheckSum;			// Backup der Checksumme

	lOldCheckSum = 987654;		// Ein Dummywert, haha! 

	// Eine Endosschleife, wenn eine Taste gedrueckt wurde,
	// wird eine Meldung ausgegeben.
	while (1)
	{	// Anfang while(1)
		
		lCheckSum = 0;	// Summe auf 0 setzen
		
		// Eine For-schleife, für jede Taste zu 
		// durchlaufen.
		for (int i = 0; i < 256; i++)
		{	// Anfang for (int i = 0; i < 256; i++)
			
			sKeyState = GetAsyncKeyState(i);	// Den Status der Taste holen
			lCheckSum += sKeyState;				// Der Prüfsumme den Wert zuweisen
			sArrKeyState[i] = sKeyState;			// Im Array eintragen

		}	// Ende for (int i = 0; i < 256; i++)

		// Überprüfen der Prüfsummen
		if (lOldCheckSum != lCheckSum)
		{	// Anfang	if (OldCheckSum != CheckSum)
		      
			// Jetzt  eine For-Schleife für jede Taste, die im Array zu finden ist.
			for (int i = 0; i < 256; i++)
			{	// Anfangfor (int i = 0; i < 256; i++)
				
				// Wenn dieser Wert auftritt, so ist die Taste gedrückt.
				if (sArrKeyState[i] == -32767)
				{
					// Da wir ja nun wissen, dass die Taste gedrockt wurde,
					// können wir überprüfen, ob wir die Taste verwenden können.
					
					// Der Code 112 steht für die F1 Taste. Das bedeutet, wir können
					// unsere Behandlung beginnen *G*
					if(static_cast<char>(i) == 112)
					{	// Anfang if(static_cast<char>(i) == 112)
						strcat(cMsg, cFunktionstasten[0]);
						printf(cMsg);	// Den spezifizierten Wert ausgeben
					}	// Ende if(static_cast<char>(i) == 112)
				
				}

				//printf("Key  %i  pressed", (char)i);

			}	// Ende for (int i = 0; i < 256; i++)

		}	// Ende if (OldCheckSum != CheckSum)
		
		lOldCheckSum = lCheckSum;

	}	// Ende while(1)




}	// Ende der Funktion void CheckKey(void *ptrDummy)

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

/*********************************************************************	
	Name der Funktion:	GetLine
	Parameter:			char* = der String, der gelesen werden soll, 
						FILE* = die Datei, in der gelsen wird.
	Rückgabewert:		int, 0 = Fehlschlag, 1 = Erfolg
	Zweck:				Liest in einer Datei, bis es eine Zeile findet
**********************************************************************/

int GetLine(char *ptrString, FILE *ptrFile)
{	// Anfang der Funktion GetLine
	
	// Die Zeile finden, die Infos enthält
	while(1)
     {
		//Aktuelle Zeile bekommen
		if (!fgets(ptrString, MAXIMAL_CHARS_IN_FILES, ptrFile))
			return(0);	//Fehler, Datei existiert nicht, etc.

		//Wir haben einen String gefunden, nun gucken wir, ob er gut ist.
		for (unsigned int nScan = 0; nScan < strlen(ptrString); nScan++)
		{	// Anfang for (int nScan = 0; nScan < strlen(ptrString); nScan++)
			
			if (ptrString[nScan]=='[' || ptrString[nScan]==']')
			{	// Anfang if (ptrString[nScan]=='<' || ptrString[nScan]=='.')
				
				// Ein guter String, also: Erfolg!
				return(1);

            } // Ende if (ptrString[nScan]=='<' || ptrString[nScan]=='.')
			
			// Andernfalls....
			else
			if (ptrString[nScan]==';')	// Das ";" steht für einen Kommentar
				break;

		} // Ende for (int nScan = 0; nScan < strlen(ptrString); nScan++)

     } // Ende while(1)

	// Misserfolg zurückgeben
	return(0);

} // Ende der Funktion GetLine

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

/*********************************************************************	
	Name der Funktion:	ParseValue
	Parameter:			char* = Die Quelle, in der gesucht wird,
						char* = Der Wert, der gelesen wird
	Rückgabewert:		int, 0 = Fehlschlag, 1 = Erfolg
	Zweck:				Sucht nach dem Wert zwischen den ""
**********************************************************************/

int ParseValue(char *ptrSource, char *ptrValue)
{	// Anfang der Funktion int ParseValue(char *ptrSource, char *ptrValue)

	unsigned int nStart = 0,   // Anfang des Werts
			 nEnd   = 0;   // Ende des Werts

	// Das erste Anführungszeichen finden
	while((ptrSource[nStart]!='"') && (nStart < strlen(ptrSource)))
		nStart++;

	// Nach Fehler suchen
	if (nStart >= strlen(ptrSource))
		return(0); //Und Misserfolg zurückgeben

	// Kalibrierung...
	nEnd = ++nStart;

	// Das zweite Anführungszeichen finden (oder auch nicht)
	while((ptrSource[nEnd]!='"') && (nEnd < strlen(ptrSource)))
		nEnd++;	// Das Ende des Strings hochzählen

	// Gab es einen Fehler?
	if (nEnd >= strlen(ptrSource))
		return(0);	// Ja! Also: Misserfolg!

	// Nun wird der Wert kopiiiiiiiiiiiiiiiiert *g*
	memcpy(ptrValue, &ptrSource[nStart], nEnd - nStart);

	// Und das ganze Nullterminieren...
	ptrValue[nEnd - nStart] = 0;

	// Ja, Ja, Ja! Ein Erfolg!
	return(1);

} // Ende der Funktion int ParseValue(char *ptrSource, char *ptrValue)

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

/****************************************************************
	Funktionsname:	CloseSockets
	Parameter:		Keine 
	Rückgabewert:	Keiner
	Zweck:			Aufrufen zum Beenden aller Verbindungen
******************************************************************/

void CloseSockets(void)
{	// Anfang der Funktion CloseSockets
	
	// Variable für die Fehlerbehandlung
	int nError = 0; 

	// Die Adresse löschen
	memset(&TargetAddress, 0, sizeof (TargetAddress));

	// Socket schließen, dabei darauf achten, dass es keinen Fehler gab
	if(nError = shutdown(nSocket, 2) != 0 && nError != WSAENOTSOCK)
		printf("Es gab einen Fehler, als ich den Socket schliessen wollte!\n");

}	// Ende der Funktion CloseSockets


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

/*****************************************************************************
	Funktionsname:	ReceiveData
	Parameter:		Keine (Thread)
	Rückgabewert:	Keiner
	Zweck:			Wird einmal aufgerufen und empfängt dann konstant Daten
******************************************************************************/

void ReceiveData(void *Dummy)
{	// Beginn der Funktion ReeiveData
	
	// Endlosschleife
	while(bConnected)
	{	// Anfang while(bConnected)

		// Empfangen der Daten, aber nur, wenn man verbunden ist
		if(bConnected)
		{	// Anfang if(bConnected)

			nCount = recv(nSocket, cData, sizeof(cData), 0);

			// Rudimentäre Fehlerbehandlung
			if(nCount == SOCKET_ERROR)
			{ // Anfang if(nCount == SOCKET_ERROR)
				
				printf("Hmm. Komisch. Ich konnte keine Daten mehr empfangen, \n"
					   "wahrscheinlich ist die Verbindung gekappt, oder?\n");

				// Flag setzen
				bConnected = false;

			} // Ende if(nCount == SOCKET_ERROR)
			
			
			/*
			
			// Überprüfen, ob die Nachricht den gesendeten Daten entspricht
			// Das hab ich auskommentiert, weil ich's in den meisten Fällen
			// nicht gebraucht habe.

			if(strstr(cData, cMsg) == NULL && strlen(cData) != 0 && strlen(cMsg) != 0 || strlen(cMsg) == 0 && bConnected)
				
			*/

			// Was hier steht, ist sinnlos, da es,
			// weil nicht definiert, nie ausgeführt wird. Sollte
			// jedoch irgendwann einmal jemand diese Ergebenisse 
			// brauchen, so kann er das Symbol definieren.
			
			#ifdef I_WANT_TO_SEE_ALL_DEBUG_MSGS
			
			printf("%i", (int)cData[nCount - 3]);
			printf("Groesse nCount = %i\n", nCount); 
			
			#endif
			
			// DEBUG:
			// Gibt das letzte Zeichen des Strings, bevor dieser
			// nullterminiert wird, aus.
			/*

			printf("%c oder %i", cData[nCount - 2], (int)cData[nCount - 2]);

			*/

			// Wir führen nun eine Nullterminierung der Daten durch.
			if(nFindDuplicates != 0)
				cData[nCount - 2] = '\0';

			// DEBUG:
			// Gibt das letzte Zeichen des Strings, nachdem dieser nullterminiert
			// wurde, aus
			/*
			
			printf("%c oder %i", cData[nCount - 2], (int)cData[nCount - 2]);
			
			*/
			
			/*
			
			// Jetzt suchen wir in den Daten nach dem Wert, der im globalen
			// Puffer untergebracht ist.
			
			if(Search_1(cData, cGlobalBuffer, nCount - 2) == 1)
				printf("Der Wert wurde gefunden!");
			
			*/

			/*
			
			// Überprüfen, ob die Strings identisch sind!
			if(strstr(cData, cGlobalBuffer))
				printf("Die Werte erscheinen identisch!\n");

			*/

			// Was macht eine Funktion namens write?
			// Richtig! Sie zerstört das Internet *g*. Sorry, bin übermüdet.
			// Aber vorher wird noch gecheckt, ob man verbunden ist
			if(bConnected && nFindDuplicates != 0 && (strcmp(cData, cGlobalBuffer) != 0) && Search_1(cData, "__file", strlen(cData)) == 0)
				write(1, cData, nCount);
			else
			{	// Anfang else

				if(bConnected && Search_1(cData, "__file", strlen(cData)) == 0)
					write(1, cData, nCount);

				// Überprüfung, ob eine Datei empfangen wird
				if(bConnected && Search_1(cData, "__file", strlen(cData)) == 1)
				{	// Anfang if(bConnected && Search_1(cData, "__file", strlen(cData)) == 1)

					char cBuffer[11]		= { 0 };	// Ein Puffer
					char cFilename[1001]	= { 0 };	// Der zu extrahierende Dateiname
					char cFigure			= { 0 };	// Das empfangene Zeichen
					char cCopy[81]			= { 0 };	// Der Dateiname der Kopie
					
					// Dateinamen extrahieren
					sscanf(cData, "%s %s %s", cBuffer, cFilename, cCopy);

					// Versuchen, die Datei zu öffnen
					FILE *pFile = fopen(cCopy, "wb");
					//FILE *pTest = fopen("c:\\mytest.txt", "wb");

					// Fehlertest
					if(pFile == NULL)
						printf("\nKonnte angeforderte Datei nicht oeffnen!\n\n");

					// Dieser Code wird solange ausgeführt, bis der Befehl
					// zum Schließen kommt.
					while(strstr(cBuffer, "file______") == NULL)
					{	// Anfang while(Search_1(cData, "file__", strlen(cData)) == 0)
					
						// Daten epmfangen
						recv(nSocket, cBuffer, sizeof(cBuffer), 0);

						// Zeiger auf die Daten initialisieren
						char *pData = cBuffer;

						// Zeiger inkrementieren
						pData++;

						// Wert der Zahl umwandeln
						cFigure = atoi(pData);

						// Vergleichen des Puffers mit dem Beenden-Kommando
						if((strstr(cBuffer, "file______")) == NULL)	
							fputc(cFigure, pFile);
		
					}	// Ende while(Search_1(cData, "file__", strlen(cData)) == 0)

					printf("Code zum Beenden.");

					// Ende erreicht, ergo: Datei schließen
					fclose(pFile);

				}	// Ende if(bConnected && Search_1(cData, "__file", strlen(cData)) == 1)

			}	// Ende else

			// Überprüfen, ob geloggt werden soll:
			if(nLogging != 0)
				logData(cData);
			
			/*

			// Wenn das letzte Zeichen der empfangenen Daten kein Zeilenumbruch ist,
			// so wird noch schnell einer ausgegeben. 
			// Kommentiert's von mir aus aus *lol*. Aber bisher war auch 
			// das unnötig.

			//if(cData[strlen(cData) - 1] != '\n')
			//printf("\n");
			
			// Kommentiert diese Zeile aus, wenn ihr die 
			// Sockets anders erstellen wollt (mit einem SOCKET-Objekt)

			//count = recv(SocketData, Data, sizeof(Data), 0);

			*/
			
		} // Ende if(bConnected)
		
	}	// Ende while(bConnected)

	// Die Adresse löschen
	memset(&TargetAddress, 0, sizeof (TargetAddress));
		
	// Beendet den Thread
	_endthread();

}	// Ende der Funktion ReiceiveData

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

/******************************************************
	Name der Funktion:	SendData
	Parameter:			Keine (Thread)
	Rückgabewert:		Keiner (Thread)
	Zweck:				Sendet Daten
*******************************************************/

void SendData(void *Dummy)
{	// Anfang der Funktion SendData
	
	// Ganz wichtig: Diese Variable heißt
	// genauso wie ihr globales Gegenstück. Hier ist sie jedoch
	// nur LOKAL!
	char cMsg[512] = {0};
	
	// Variable für den Rückgabewert von send(...)
	int nError = 0;

	// Solange ausführen, wie man verbunden ist
	while(bConnected)
	{	// Anfang while(bConnected)
		
		// Warten auf INPUT *Lol*
		WaitForSingleObject(hInput,INFINITE);
		// Was bedeuetet wohl "Read", wie wär's mit
		// Lesen der Eingabe?

		// Und jetzt ** Trommelwirbel **
		// Eingabebehandlung!
		// ** Applaus **
		ReadFile(hInput, cMsg, sizeof(cMsg), &nRead, NULL);

		// Was hier steht, ist sinnlos, da es,
		// weil nicht definiert, nie ausgeführt wird. Sollte
		// jedoch irgendwann einmal jemand diese Ergebenisse 
		// brauchen, so kann er das Symbol definieren.
		#ifdef I_WANT_TO_SEE_ALL_DEBUG_MSGS
		
		printf("Groesse nRead = %i\n", nRead);

		// Kopieren der Eingabe in den globalen Puffer
		//strcpy(cGlobalBuffer, cMsg);
	
		printf("%i", (int)cMsg[nCount - 3]);
		
		
		// Wir durchkämmen nun das gesamte Feld und sichern jeden einzzelnen
		// Integer-Wert des Puffers
		for(unsigned int i = 0; i < strlen(cMsg) + 1; i++)
		{	// Anfang for(unsigned int i = 0; i < strlen(cMsg) + 1; i++)
			
			char cBuffer[512];	// Der Puffer

			// Kopieren des Zeichens in den Puffer
			sprintf(cBuffer, "%i", cMsg[i]);
			
			// Den Puffer loggen
			logData(cBuffer);

		}	// Ende for(unsigned int i = 0; i < strlen(cMsg) + 1; i++)

		#endif

		// Nun loggen wir den gesamten String als solchen
		if(nLogging != 0)
			logData(cMsg);

		// Die Eingabe behandeln
		HandleInput(cMsg);

		// Senden der Daten
		nError = send(nSocket, cMsg, nRead, 0);

		#ifdef I_WANT_TO_SEE_ALL_DEBUG_MSGS

		printf("Wichtig: %s", cGlobalBuffer);

		#endif

		
		// Nullterminierung der Eingabe, so nötig.
		if(nFindDuplicates != 0)
		{	// Anfang if(nFindDuplicates != 0)

			cMsg[strlen(cMsg) - 2] = '\0';
			strcpy(cGlobalBuffer, cMsg);
		
		}	// Ende if(nFindDuplicates != 0)

		
		
		// Was hier steht, ist sinnlos, da es,
		// weil nicht definiert, nie ausgeführt wird. Sollte
		// jedoch irgendwann einmal jemand diese Ergebenisse 
		// brauchen, so kann er das Symbol definieren.
		#ifdef I_WANT_TO_SEE_ALL_DEBUG_MSGS
		
		// Wir durchkämmen nun das gesamte Feld und sichern jeden einzzelnen
		// Integer-Wert des Puffers
		for(i = 0; i < strlen(cGlobalBuffer) + 1; i++)
		{	// Anfang for(i = 0; i < strlen(cGlobalBuffer) + 1; i++)
			
			char cBuffer[512];	// Der Puffer

			// Kopieren des Zeichens in den Puffer
			sprintf(cBuffer, "%i", cGlobalBuffer[i]);
			
			// Den Puffer loggen
			logData(cBuffer);

		}	// Ende for(i = 0; i < strlen(cGlobalBuffer) + 1; i++)

		// Nun loggen wir den gesamten String als solchen
		logData(cGlobalBuffer);		

		#endif

		// Kleine Fehlerbehandlung
		if(nError == SOCKET_ERROR && bConnected)
		{	// Anfang if(nError == SOCKET_ERROR)

			printf("\nSowas aber auch! Da gab's doch tatsaechlich einen Fehler,\n"
			   "als ich Daten versenden wollte.\n");

			// Flag zum Trennen setzen
			bConnected = false;

			// Adresse löschen
			memset(&TargetAddress, 0, sizeof (TargetAddress));

		}	// Ende if(nError == SOCKET_ERROR)
	
	}	// Ende while(bConnected)

	// Thread beendet
	_endthread();

}	// Ende der Funktion SendData

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

/*********************************************************************************
	Name der Funktion:	StartTelnet
	Parameter:			Keine
	Rückgabewert:		Keiner
	Zweck:				Stellt Behandlungen fürs Empfangen und Senden von Daten
						vor.
***********************************************************************************/

void StartTelnet(void)
{	// Anfang der Funktion StartTelnet
	
	// Die Threads zum Senden....
	_beginthread(SendData, 0, NULL);
	// Und zum Empfangen!
	_beginthread(ReceiveData, 0, NULL);
	
	// Er verharrt solange in dieser Funktion, bis keine Verbindung mehr besteht
	while(bConnected);

}	// Ende der Funktion StartTelnet

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

/***************************************************************************
	Name der Funktion:	FindCmd
	Parameter:			char* = das Feld, in dem gesucht werden soll
	Rückgabewert:		int = Nummer des Kommandos, das gefunden wurde. 
						Diese Nummer ist durch das Enum festgelegt.
	Zweck:				Sucht in einem Feld nach einem Kommando
****************************************************************************/


int FindCmd(char *Feld, int nLength)
{	// Anfang der Funktion FindCmd
	
	// Durchkämmen des Feldes
	for(int i = 0; i < sizeof Kommandos /sizeof Kommandos[0]; i++)
	{	// Anfang for(int i = 0; i < sizeof Kommandos /sizeof Kommandos[0]; i++)
		
		// Nach dem Kommando suchen
		if (Search_1(Feld, Kommandos[i], nLength) == 1)
		{	// Anfang if
			// Erfolg!
			return i+1;	// Rückgabe der Nummer des Kommandos
		}	// Ende if

	}	// Ende for(int i = 0; i < sizeof Kommandos /sizeof Kommandos[0]; i++)
	
	return 0;	// Nix gefunden

}	// Ende der Funktion FindCmd

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

/***************************************************************
	Funktionsname:	Initiate
	Parameter:		Keine
	Rückgabewert:	Keiner
	Zweck:			Initiiert die Sockets und WinSock.
					Mit dabei: Eine coole Fehlerbehandlung
*****************************************************************/

void Initiate(void)
{	// Anfang der Funktion Initiate

	// Die Version 1.1 von WinSock anfordern.
	// Wenn die vorhandene Version besser ist, wird kein Fehler
	// zurückgegeben, isz sie älter, geht gar nichts mehr.
	// Durch die Version 1.1 müsste das Programm auch unter Windows 95 laufen.

	wVersionRequested = MAKEWORD (1, 1);

	// Starten von WinSock, rudimentäre Fehlerbehandlung
	if(nError = WSAStartup (wVersionRequested, &WinsockData) != 0) 
	{	// Anfang if
		// Fehlermeldung anzeigen
		printf("Das Starten von WinSock schlug fehl. Ist die Version der DLL korrekt?\n");

		// Auf Tastendruck warten
		getchar();
		
		//Beenden des Programms
		exit(1);
	}	// Ende if

	// Initialisierung des Sockets.
	// Endlich eine richtige Fehlerbehandlung!
	nSocket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP); 

	switch(nSocket)
	{	// Anfang switch(iSocket)
		// WinSock nicht initialisiert...da ist was faul *Lol*
		case WSANOTINITIALISED:

			// Das ist doch noch freundlich, oder?
			printf("Du bloeder Cracker! Was hast du mit meinem Programm gemacht?\nDieser Meldung"
				   " darf gar nicht erscheinen, also ist irgendwas mit dem Programmcode falsch!\n");

			// Auf Tastendruck warten
			getchar();			
			
			// Und wieder beenden
			exit(1);
			
			// Das wird wohl kaum nötig sein
			break;

		// Das Netz ist down, komisch...
		case WSAENETDOWN:

			// Und wieder ein Fehler...
			printf("Mensch! Ich habe versucht, einen Socket zu erstellen, und da sagt mir doch Windows tatsächlich:\n"
				   "The network subsystem or the associated service provider has failed.\n"
				   "Kannst du dir sowas vorstellen? Schade.\n");

			// Auf Tastendruck warten
			getchar();

			// Beenden
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		// Keine Unterstützung der Adresfamilie
		case WSAEAFNOSUPPORT:
			
			// Fehler über Fehler
			printf("Hui...was ist denn mit deinem PC los? Ich habe VERSUCHT, einen Socket zu erstellen, "
				   "da meldet sich Windoof und sagt mir:\n"
				   "The specified address family is not supported.\n"
				   "Das ist ja nun wirklich Sch...!\n");

			// Auf Tastendruck warten
			getchar();

			// Beenden
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		case WSAEINPROGRESS:

			// Wieder mal...
			printf("Aber, aber! Da läuft heute was schief, ich kann dir sagen! Bisher lief alles gut, aber dann "
				   "kam der grosse Zusammenbruch. Windows meinte:\n"
				   "A blocking Windows Sockets 1.1 call is in progress, or the service "
				   "provider is still processing a callback function.\n"
				   "Klingt bloed, gell?\n");

			// Auf Tastendruck warten
			getchar();

			// Beenden
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		case WSAEMFILE:

			// Na, was ist wohl los?
			printf("Also sowas! Dieser PC, ich bin gerade mitten in der Arbeit, was passiert? "
				   "Ein Fehler tritt auf. Ist das bloed. Sieh dir's mal selbst an:\n"
				   "No more socket descriptors are available.\n"
				   "Man kann eben nicht immer alles haben!\n");

			// Auf Tastendruck warten
			getchar();

			// Beenden *gähn*
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		case WSAENOBUFS:

			// Langsam nervt's!
			printf("Das ist peinlich! Was hast du mit deinem PC gemacht? 8mb RAM oder so? "
				   "Versuch nicht, dich rauszureden! Windows hat's mir genau erzaehlt:\n"
				   "No buffer space is available. The socket cannot be created.\n"
				   "Das verdient eine Strafe *g*!\n");

			// Auf Tastendruck warten
			getchar();

			// was machen wir wohl jetzt?
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		case WSAEPROTONOSUPPORT:

			// Der ist laaaaaasch
			printf("Heute geschehen komische Sachen, ehrlich! Weisst du was? Windows sagt mir "
				   "gerade:\n"
				   "The specified protocol is not supported.\n"
				   "Pech gehabt.\n");

			// Auf Tastendruck warten
			getchar();
			
			// Starten der Atomfusion, um die Nuklearraketen des
			// PCs abzufeuern 
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		case WSAEPROTOTYPE:

			// Der ist ja ganz komisch!
			printf("Was zum Schmunzeln: Windows hat mir gerade den folgenden Witz erzaehlt:\n"
				   "The specified protocol is the wrong type for this socket.\n"
				   "Gut, gell?\n");

			// Auf Tastendruck warten
			getchar();

			// Die Elektrolyse starten
			exit(1);

			// Das wird wohl kaum nötig sein
			break;


		case WSAESOCKTNOSUPPORT:

			// Boah! Noch einer!
			printf("Heute ist nicht dein Tag. WinSocket meint folgendes zu deinem Horoskop:\n"
				   "The specified socket type is not supported in this address family.\n"
				   "Also: Computer aus und in eine Ecke *Lol*!\n");

			// Auf Tastendruck warten
			getchar();

			// Funkantenne ausrichten...
			exit(1);

			// Das wird wohl kaum nötig sein
			break;

		default:

			// Endlich eine gute Nachricht!
			printf("\nSocket reibungslos erstellt. Hey, hoerst du mir ueberhaupt zu?\n\n");
			
			// Das wird wohl kaum nötig sein
			break;

	}	// Ende switch(iSocket)

	// Damit dürfte alles reibungslos verlaufen sein.

}	// Ende der Funktion Initiate



// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

/*****************************************************************
	Funktionsname:	HandleInput
	Parameter:		char = Das Feld, in dem gesucht werden soll
	Rückgabewert:	Keine
	Zweck:			Behandlung der Eingabe
******************************************************************/
void HandleInput(char cInput[8192])
{	// Anfang der Funktion HandleInput

	// Suchen wir mal nach Kommandos
	
	int nCommand = FindCmd(cInput, strlen(cInput));

		switch(nCommand)
		{	// Anfang switch(nCommand)
			
		
		// Der Benutzer will sich verbinden	
		case CONNECT:
				
			// Intiierung von WinSock und dem Socket
			Initiate();
				
				if(3 != sscanf(cInput, "%s %s %s", cKommando, cParameter_1, cParameter_2)  && !bConnected)
				{	// Anfang if
					
					// Fehlertext ausgeben
					printf("\nSo, so, du willst dich also mit einem Server verbinden."
						   "\nDann hast du aber vergessen, dass du 2 Parameter angeben musst.\n"
						   "Und zwar: 1. Den Namen oder die IP des Servers\n"
						   "          2. Den Port, an dem der Server arbeitet.\n"

						   // Schleichwerbung
						   "\nAlso beispielsweise: connect unitopia.uni-stuttgart.de 23\n\n");

				}	// Ende if
				
				else
				{	// Anfang else
					
					// Er ist noch nicht verbunden
					if(!bConnected)
					{ // Anfang if(!bConnected)
					
						// Jetzt lösen wir den Namen des Hosts in eine IP-Adresse auf...
					
						host_info = gethostbyname(cParameter_1);
					
						// oder auch nicht!
						if (host_info == NULL) 
						{	// Anfang if (NULL == host_info) 
		
							// Fehlermeldung
							printf("\nDa muss dir wohl ein Fehler unterlaufen sein!\n"
							       "Ich zumindest kenne den Server \"%s\" nicht\n", cParameter_1);
		
							break;	
							
						} // Ende if (NULL == host_info) 
						
						
						memset(&TargetAddress, 0, sizeof (TargetAddress));
						TargetAddress.sin_family = host_info->h_addrtype;

						memcpy( (char *)&TargetAddress.sin_addr, host_info->h_addr, host_info->h_length);
						TargetAddress.sin_port = htons(atoi(cParameter_2)); 

						if(nError = connect(nSocket, (struct sockaddr*)&TargetAddress, sizeof(TargetAddress)) != 0)
						{ // Anfang if(iError = connect(iSocket, (struct sockaddr*)&TargetAddress, sizeof(TargetAddress)) != 0)
							
							// Die Fehlermeldung ausgeben
							printf("\nDa ist wohl ein Fehler aufgetreten, als ich mich\nzu dem Host %s am Port "
                                   "%s verbinden wollte.\n\n" 
							       "Bitte alle Daten ueberpruefen!\n", host_info->h_name, cParameter_2);

							break;

						} // Ende if(iError = connect(iSocket, (struct sockaddr*)&TargetAddress, sizeof(TargetAddress)) != 0)

						bConnected = true;
					
						// Dann hat ja doch alles geklappt
						//printf("\nCaptain, die Verbindung zu %s auf Port %s steht, Sir!\n\n", 
						//	   host_info->h_name, cParameter_2);
						
						// NEU:
						// Anstelle eines festen Strings wird nun der in der Konfigurationsdatei
						// spezifizierte Wert ausgegeben.
						strcat(cStatusMsg[0], "\n");				// Anhängen einer neuen Zeile an den String
						printf(cStatusMsg[0], 
							   host_info->h_name, cParameter_2);	// Ausgen der Meldung

						// Das ist die IP-Adresse des Hosts. Aus Nervigkeitsgründen
						// wird diese nicht mit angezeigt.
						//printf("Die Adresse normal: \n%s", inet_ntoa(TargetAddress.sin_addr));

						// Telnet starten!
						StartTelnet();

					} // Ende if(!IsConnected)
					
					else
						printf("\nMoment mal! Du bist doch schon mit %s verbunden!\n", host_info->h_name);

				}	// Ende else

				// Und ein break
				break;

			
		// Der Benutzer möchte beenden
		case QUIT:
		case ENDE:
		case EXIT:

				// Socket schließen und Benutzer benachrichtigen
				CloseSockets();

				// Ist der Benutzer verbunden? Wenn ja, so wird die Verbindung gekappt
				if(bConnected)
					bConnected = false;
				
				// WinSock herunterfahren und Benutzer benachrichtigen
				WSACleanup(); 
				printf("\nWinSock wurde beendet.\n");

				// Was macht dieser Code wohl?
				printf("\nBeliebige Taste zum Beenden druecken!\n\n");
				// Auf Tastendruck warten
				_getch();

				// Und jetzt richtig beenden
				exit(0);

				// Wieder ein Break
				break;

		// Verbindung trennen
		case DISCONNECT:

				// Was wird man wohl bei Disconnect machen?
				if(bConnected)
				{	// Anfang if(bConnected)
					
					// Den Socket schließen
					CloseSockets();
					
					// Flag setzen
					bConnected = false;

				}	// Ende if(bConnected)

				break;

		// Default	
		default:

				break;
		
		}	// Ende switch(iCommand)

}	// Ende der Funktion HandleInput

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

/***************************************************************************
	Dies ist die Hauptschleife des Programms. Sie hat den folgenden Zweck:
	- Initialisierung von WinSock
	- Informationen und Interface für den Benutzer
	- Herstellen einer Verbindung
	- Senden von Daten, bis der Befehl zum Beenden gegeben wird
*****************************************************************************/


int main(void)
{	/// Anfang der Funktion main

	
	// Das HANDLE hInput mit den Informationen für stdin füllen
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	
	// Jetzt den Modus der Konsole anpassen. 
	// Meines Wissens nach müsste man das unter DOS nicht machen. 
	// Das waren eben noch schöne Zeiten, gell?
	SetConsoleMode(hInput,ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);
	
	// Das ist das Intro, hoffe ich *lol*
	printf("\t\t\t       [=[Garton 1.7]=]\t\t\t\n"
		   "\t\t\t       ----------------\t\t\t\n\n");


	// Nun wird die Datei mit den Einstellungen geladen.
	FILE *ptrIniFile = NULL;
	
	// Laden der Inidatei
	if((ptrIniFile = fopen(NAME_OF_INIFILE, "r")) == NULL)
	{	// Anfang if(ptrIniFile = fopen(NAME_OF_INIFILE, "r") == NULL)

		// Fehlermeldung
		printf("Tut mir leid, aber ich konnte die INI-Datei nicht oeffnen!\n\n");

		// Tastendruck
		_getch();

	}	// Ende if(ptrIniFile = fopen(NAME_OF_INIFILE, "r") == NULL)

	char cBuffer[MAXIMAL_CHARS_IN_FILES];	// 200 Zeichen für den Puffer reservieren. In diesen Puffer
											// laden wir dann den Text für die Funktionstasten
	
	// Jetzt starten wir eine Schleife für allr benutzten Funktionstasten
	for(int i = 0; i < NUMBER_OF_USED_FUNCTION_KEYS; i++)
	{	// Anfang for(int i = 0; i < NUMBER_OF_USED_FUNCTION_KEYS; i++)
		
		GetLine(cBuffer, ptrIniFile);			// Jetzt lesen wir eine Zeile
		ParseValue(cBuffer, cBuffer);				// Und geben den Wert ein

		strcpy(cFunktionstasten[i], cBuffer);

	}	// Ende for(int i = 0; i < NUMBER_OF_USED_FUNCTION_KEYS; i++)

	// Jetzt starten wir den Thread für die Tastenbehandlung
	//_beginthread(CheckKey, 0, NULL);

	// Jetzt müssen die spezifischen Fehlermeldungen eingelesen werden
	GetLine(cBuffer, ptrIniFile);
	ParseValue(cBuffer, cBuffer);
	strcpy(cStatusMsg[0], cBuffer);

	// Nun wird der Wert für die Duplikat-Funktion eingelesen
	GetLine(cBuffer, ptrIniFile);
	ParseValue(cBuffer, cBuffer);
	// Konvertierung des Wertes
	nFindDuplicates = atoi(cBuffer);

	// Jetzt kommt das Loggen dran
	GetLine(cBuffer, ptrIniFile);
	ParseValue(cBuffer, cBuffer);
	// Und wieder wird der Wert konvertiert
	nLogging = atoi(cBuffer);

	// Nun sind die Funktionstasten und der andere Kram eingelesen und 
	// wir starten die Whileschleife
	while(1)
	{	// Anfang while
		
		// Das lässt Telnetflair aufkommen!
		if(!bConnected)
		{
			printf("> ");
			gets(cMsg);

			HandleInput(cMsg);
		}

	}	// Ende while

	delete ptrIniFile;

	// Rückgabe eines Werts
	return(1);

}	// Ende der Funktion main

// ---------------------------------------------------------------------------