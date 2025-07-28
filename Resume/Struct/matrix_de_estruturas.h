/* Um exemplo simples de lista postal usando uma 
   matriz de estruturas. */
#pragma once
#include <iostream>
#include <sstream> // stringstream()
#include <stdio.h>
#include <string>
#include <stdlib.h>

#define MAX 100

struct addr {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
} addr_info[MAX];

static void init_list(void) {
	register int t;
	for(t = 0; t < MAX; ++t)
		addr_info[t].name[0] = '\0';
}
/* Obtém a seleção. */
static char menu_select(void) {
	std::string s;
	int  i=0;

	printf("\n1. Inserir um nome\n");
	printf("2. Excluir um nome\n");
	printf("3. Listar o arquivo\n");
	printf("4. Sair\n");

	do { 
		printf("\nDigite sua escolha: ");
		std::cin.clear();
		getline(std::cin, s);
		i = s[0]-48;
	} while(i<1 || i>4);

	return i;
}
/* Encontra uma estrutura não usada. */
int find_free(void) {
	register int t;
	for(t = 0; addr_info[t].name[0] && t < MAX; ++t);
	if(t == MAX) 
		return -1; /* nenhum elemento livre */
	return t;
}
/* Insere os endereços na lista. */
static void enter(void) {
	int slot;
	char str[80];

	slot = find_free();
	if(slot == -1) {
		printf("\nLista cheia");
		return;
	}

	printf("Digite o nome: ");
	gets(addr_info[slot].name);

	printf("Digite a rua: ");
	gets(addr_info[slot].street);
	
	printf("Digite a cidade: ");
	gets(addr_info[slot].city);

	printf("Digite o estado: ");
	gets(addr_info[slot].state);
	
	printf("Digite o cep: ");
	gets(str);
	addr_info[slot].zip = strtoul(str, '\0', 10);
}

/* Apaga um endereço. */
static void deleta(void) {
	register int slot;
	char s[80];

	printf("Digite o registro #: ");
	gets(s);
	slot = atoi(s);
	if(slot >= 0 && slot < MAX)
		addr_info[slot].name[0] = '\0';
}
/* Mostrar a lista na tela. */
static void list(void) {
	register int t;

	for(t = 0; t < MAX; ++t) {
		if(addr_info[t].name[0]) {
			printf("%s\n", addr_info[t].name);
			printf("%s\n", addr_info[t].street);
			printf("%s\n", addr_info[t].city);
			printf("%s\n", addr_info[t].state);
			printf("%lu\n", addr_info[t].zip);
		}
	}
	printf("\n\n");
}
static void _matrixDeEstruturas() {
	int choice;
	init_list(); /* inicializa a matriz de estruturas */
	while(true) {
		choice = menu_select();
		switch(choice) {
		case 1: enter();
			break;
		case 2: deleta();
			break;
		case 3: list();
			break;
		case 4: exit(0);
		}
	}
}