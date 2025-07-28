/* Suchen- und Ersetzenfunktion für char-Arrays */

#define MAXIMAL_CHARS 500 /* 500 Zeichen müssten reichen */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* 1. Implementierung: Sie läuft mithilfe eines Zeigers */
char Search_with_pointer(char *CharToSearchIn, char CharToSearchFor[MAXIMAL_CHARS])
{
	int i = 0;	
	while(*CharToSearchIn)
	{
		if (*CharToSearchIn == CharToSearchFor[i])
		{
			CharToSearchIn++; /* Zum nächsten Zeichen "hangeln" */
			i++;
		}
		else
			CharToSearchIn++;
			//break;
	}
	
	if (strlen(CharToSearchFor) == i) /* Kann man hier auch "*CharToSearchIn" schreiben? */
		return(1);
	else
		return(0);
}

/* 2. Implementierung: Sie läuft nun ohne Zeiger */

char Search_without_pointer(char CharToSearchIn[MAXIMAL_CHARS], char CharToSearchFor[MAXIMAL_CHARS])
{
	int j = 0;
	
	for (int i = 0; i  <= strlen(CharToSearchIn); i++)
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

int main()
{
	signed char Eingabe[MAXIMAL_CHARS];
	signed char Suchtext[MAXIMAL_CHARS];

	printf("Bitte geben Sie einige Buchstaben ein: ");
	gets(Eingabe);
		
	printf("\nNach welchen Buchstaben soll ich suchen? ");
	gets(Suchtext);
	
	if (Search_with_pointer(Eingabe, Suchtext))
				printf("\aDie Buchstabenkombination '%s' wurde gefunden!\a\n", Suchtext);
	else
		printf("Nicht gefunden!\a\n");

	if (Search_without_pointer(Eingabe, Suchtext))
		printf("\aDie Buchstabenkombination '%s' wurde gefunden!\a\n", Suchtext);
	else
		printf("Nicht gefunden!\a\n");
	

	return(0);
}