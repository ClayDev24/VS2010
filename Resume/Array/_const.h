#pragma once
#include <iostream>
/*
🔒 const em Arrays Estáticos Unidimensionais
	-const=> pode ser aplicada de diferentes formas ao declarar arrays. Protege dados contra modificações acidentais.
*/

void printArray(const int arr[], int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

static void _constUsage() {
	// array com elementos constantes:
    const int myArray[] = {10, 20, 30, 40, 50};
    printArray(myArray, 5);

    // myArray[1] = 99; // ERRO: tentativa de modificar const

    int normalArray[] = {1, 2, 3, 4, 5};
    int* const p = normalArray; // ponteiro constante

    p[0] = 100; // OK
    // p = new int[5]; // ERRO: ponteiro é constante

    printArray(normalArray, 5);
}
