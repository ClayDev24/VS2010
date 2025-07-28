#pragma once

struct Estrutura {
	int i;
	//void func(); // C++ Function cannot be member of struct
};

static void func() {
	printf("Functions can never be struct members!\n");
};
