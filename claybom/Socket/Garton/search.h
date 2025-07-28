/////////////////////////////////////////////////////////////////////////////////////////
/*
	Name der Datei: search.h
	Zweck: Suchen in der Eingabe des Benutzers
	Autor: Bastian Rieck
	Copyright (c) 2001 liegt beim Autor
*/
/////////////////////////////////////////////////////////////////////////////////////////

//INCLUDES UND DEFINES///////////////////////////////////////////////////////////////////
#define MAXIMAL_CHARS 500 //8192 Zeichen müssten reichen, um in einem String zu suchen

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUGE

/////////////////////////////////////////////////////////////////////////////////////////
void CountBack(char*, const int);

//1. INPLEMENTIERUNG: MIT EINEM ZEIGER///////////////////////////////////////////////////
int Search_1(const char *CharToSearchIn, const char CharToSearchFor[MAXIMAL_CHARS],const int Laenge = 0)
{
	unsigned int i = 0;	//ZUM ZÄHLEN DER BUCHSTABEN
	/////////////////////
	int LeerzeichenGesamt = 0;	//DIE LEERZEICHEN INSGESAMT
	int LeerzeichenVorne = 0;	//DIE LEEERZEICHEN VOR DEM STRING
	int Buchstaben = 0;			//DIE BUCHSTABEN (GESAMT)
	/////////////////////
	

	//ZÄHLEN DER LEERZEICHEN INSGESAMT
	while(*CharToSearchIn)
	//ANFANG DER WHILE-SCHLEIFE
	{
		//ÜBERPRÜFUNG JEDES EINZELNEN BUCHSTABENS
		if (toupper(*CharToSearchIn) == ' ' || toupper(*CharToSearchIn) == '\t' || toupper(*CharToSearchIn) == '\v')
		{
			CharToSearchIn++;	 //ZUM NÄCHSTEN ZEICHEN
			LeerzeichenGesamt++; //LEERZEICHEN HOCHZÄHLEN
		}
		//WENN ES KEIN LEERZEICHEN ODER KEIN TABULATOR WAR:
		else
		{
			CharToSearchIn++;	//ZUM NÄCHSTEN ZEICHEN
		}
	}
	//ENDE DER WHILE-SCHLEIFE
	//////////////////////////////////////////////

	//ZURÜCKZAHLEN BIS ZUM ANFANG
	for(int j = 0; j < Laenge; j++)
		CharToSearchIn--; //ZUM VORIGEN ZEICHEN
	/////////////////////////////	
	//CountBack(CharToSearchIn, Laenge);
	
	
	
	//ZÄHLEN DER LEERZEICHEN VOR DEM WORT
	while(*CharToSearchIn)
	//ANFANG DER WHILE-SCHLEIFE
	{
		//PRÜFEN JEDES ZEICHENS
		if (toupper(*CharToSearchIn) == ' ' || toupper(*CharToSearchIn) == '\t' || toupper(*CharToSearchIn) == '\v')
		{
			CharToSearchIn++; //ZUM NÄCHSTEN ZEICHEN
			LeerzeichenVorne++;	//LEERZEICHEN VOR DEM WORT
		}
		//KEIN LEERZEICHEN?
		else
		{
			break; //ABBRUCH
		}
	}
	//ENDE DER WHILE-SCHLEIFE
	//////////////////////////////////////

	//ZURÜCKZAHLEN BIS ZUM ANFANG
	for(j = 0; j < LeerzeichenVorne; j++)
		CharToSearchIn--; //ZUM VORIGEN ZEICHEN HANGELN
	/////////////////////////////	
	//ZURÜCKZAHLEN BIS ZUM ANFANG
	//CountBack(CharToSearchIn, LeerzeichenVorne);

	//DEBUG KANN DEFINIERT WERDEN
	#ifdef DEBUG
	printf("%i", LeerzeichenGesamt); //AUSGABE DER LEERZEICHEN (TEST)
	#endif
	
	while(*CharToSearchIn)
	//BEGINN DER WHILE-SCHLEIFE
	{
		//UMWANDLUNG DER EINGABE IN GROSSBUCHSTABEN
		if (toupper(*CharToSearchIn) == toupper(CharToSearchFor[i])) //BEGINN IF
		{
			CharToSearchIn++; //ZUM NÄCHSTEN ZEICHEN HANGELN
			Buchstaben++; //DIE BEKANNTEN UND ÜBEREINSTIMMENDEN ZEICHEN
			i++;
		} //IF-ENDE
		
		//KEINE ÜBEREINSTIMMUNG?
		else //BEGINN ELSE
		{
			CharToSearchIn++; //ZUM NÄCHSTEN ZEICHEN
		} //ELSE-ENDE
				
	}
	//ENDE DER WHILE-SCHLEIFE
	
	//ZURÜCKZAHLEN BIS ZUM ANFANG
	//CountBack(CharToSearchIn, Laenge);
	//ZURÜCKZAHLEN BIS ZUM ANFANG
	for(int k = 0; k < Laenge; k++)
		CharToSearchIn--; //ZUM VORIGEN ZEICHEN
	/////////////////////////////	


		
	
	if (strlen(CharToSearchFor) == i) //DIE LÄNGE STIMMT ÜBEREIN
	{
		//IN DIESEM FALL (OHNE PARAMETER) WIRD 1 ZURÜCKGEGEBEN
		if((Laenge - LeerzeichenGesamt) == signed(strlen(CharToSearchFor)))
		{
			#ifdef DEBUG
			printf("Die Laenge stimmt ueberein!"); //NUR ZU TESTZWECKEN
			#endif
			return(1);
			
		}
		else
		{
			//HOCHZÄHLEN BIS ZUM LETZTEN BEKANNTEN ZEICHEN
			for(int k = 0; k < (Buchstaben + LeerzeichenVorne); k++)
				CharToSearchIn++;
			//////////////////////////////////////////////
		
			switch(*CharToSearchIn) //ÜBERPRÜFUNG DES LETZTEN BUCHSTABENS
			{
				case ' ': //WENN ES EIN LEERZEICHEN IST, SO IST ALLES OK
					
					/*//WENN DEBUG IST, DAS AUSFÜHREN
					#ifdef DEBUG
					printf("Da gibts ein Leerzeichen"); //BLÖDER KOMMENTAR
					#endif
					///////////////////////////////
					*/
					
					//ERFOLG
					return(1);
					/////////
					break;

				case '\n':
				case 13:
				case 12:
					return(1);

				//BEI JEDEM ANDEREN ZEICHEN WIRD 0 ZURÜCKGEGEBEN!
				default:
					//printf("Kenn ich net: %c", *CharToSearchIn);
					return(0);
					break;
			}
		}
		
		return(1);	//ERFOLG!
	}
	
	//ANDEERNFALLS GESCHIEHT DAS...
	else
		return(0); //MISSERFOLG
}
/////////////////////////////////////////////////////////////////////////////////////////

//2. INPLEMENTIERUNG: OHNE ZEIGER///&////////////////////////////////////////////////////
char Search_2(char CharToSearchIn[MAXIMAL_CHARS], char CharToSearchFor[MAXIMAL_CHARS])
{
	unsigned int j = 0;
	
	for (unsigned int i = 0; i  <= strlen(CharToSearchIn); i++)
	{
		if (CharToSearchIn[i] == CharToSearchFor[j])
		{
			CharToSearchIn++; 
			j++; /* Nicht zu verwechseln mit dem gleichnamigen Microdoof(r)-Produkt ;-) */
		}

		else
			CharToSearchIn++;
	}

	if (strlen(CharToSearchIn) == j)
		return (1);
	else
		return(0);
}
/////////////////////////////////////////////////////////////////////////////////////////

//DIESE FUNKTION ZÄHLT EINEN IHR ÜBERGEBENEN ZEIGER UM DIE IN ANZAHL ÜBERGEBENE ZAHL ZURÜCK
void CountBack(char *CharToCountBack, const int Anzahl)
{
	for(int i = 0; i < Anzahl; i++)
		CharToCountBack--; //ZURÜCKZÄHLEN
}
/////////////////////////////////////////////////////////////////////////////////////////

