#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <cstring>
#include <iomanip>

namespace estatico {

	// ============================================================================
	// 1. Array Unidimensional Estático
	// - Alocado na stack, tamanho fixo conhecido em tempo de compilação.
	// ============================================================================
	void print_static_array(const int arr[5]) {
		std::cout << "[1] Array Unidimensional Estatico: ";
		for (int i = 0; i < 5; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}

	// ============================================================================
	// 2. Array Multidimensional Estático
	// - Representa matriz. Alocação contígua.
	// ============================================================================
	void print_multi_array(const int arr[2][3]) {
		std::cout << "[2] Array Multidimensional Estatico:\n";
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j)
				std::cout << std::setw(3) << arr[i][j];
			std::cout << '\n';
		}
	}

	// ============================================================================
	// 3. std::array
	// - Tipo seguro com interface STL. Tamanho fixo em tempo de compilação.
	// ============================================================================
	void print_std_array(const std::array<int, 4>& arr) {
		std::cout << "[3] std::array: ";
		for (std::size_t i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}

	// ============================================================================
	// 4. std::vector
	// - Vetor dinâmico, gerencia tamanho automaticamente.
	// ============================================================================
	void print_std_vector(const std::vector<int>& vec) {
		std::cout << "[4] std::vector: ";
		for (std::size_t i = 0; i < vec.size(); ++i)
			std::cout << vec[i] << ' ';
		std::cout << '\n';
	}

	// ============================================================================
	// 5. Array de ponteiros
	// - Cada linha pode apontar para um array independente.
	// ============================================================================
	void init_pointer_array(int* arr[2]) {
		for (int i = 0; i < 2; ++i) {
			arr[i] = new int[2];
			for (int j = 0; j < 2; ++j)
				arr[i][j] = i * 10 + j;
		}
	}
	void show_pointer_array(int* arr[2]) {
		std::cout << "[5] Array de Ponteiros:\n";
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				std::cout << std::setw(3) << arr[i][j];
			std::cout << '\n';
		}
	}
	void clean_pointer_array(int* arr[2]) {
		for (int i = 0; i < 2; ++i)
			delete[] arr[i];
	}

	// ============================================================================
	// 6. Ponteiro Duplo (int**)
	// - Forma genérica e flexível de representar matriz dinâmica.
	// ============================================================================
	void init_double_ptr_array(int*** arr) {
		*arr = new int*[2];
		for (int i = 0; i < 2; ++i) {
			(*arr)[i] = new int[2];
			for (int j = 0; j < 2; ++j)
				(*arr)[i][j] = i + j;
		}
	}
	void show_double_ptr_array(int** arr) {
		std::cout << "[6] Ponteiro Duplo (int**):\n";
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				std::cout << std::setw(3) << arr[i][j];
			std::cout << '\n';
		}
	}
	// Libera a memória alocada dinamicamente
	void clean_double_ptr_array(int** arr) {
		for (int i = 0; i < 2; ++i)
			delete[] arr[i];
		delete[] arr;
	}

	// ============================================================================
	// 7. C-String (array de caracteres)
	// - Sequência de caracteres terminada por null ('\0')
	// ============================================================================
	void print_c_string(const char* str) {
		//std::cout << "[7] C-String: " << str << '\n';
		int i=0;
		while(str[i] != 0) 
			std::cout << str[i++];
		std::cout << std::endl;
	}

	static void _arraysUsage() {
		// 1. Array Unidimensional Estático
		int static_array[5] = {1, 2, 3, 4, 5};
		print_static_array(static_array);

		// 2. Array Multidimensional Estático
		int multi_array[2][3] = {{1, 2, 3}, {4, 5, 6}};
		print_multi_array(multi_array);

		// 3. std::array
		std::array<int, 4> std_array = {10, 20, 30, 40};
		print_std_array(std_array);

		// 4. std::vector
		std::vector<int> std_vector;// = {7, 8, 9, 10};
		std_vector.push_back(7);
		std_vector.push_back(8);
		std_vector.push_back(9);
		std_vector.push_back(10);
		print_std_vector(std_vector);

		// 5. Array de ponteiros
		int* pointer_array[2] = {nullptr, nullptr};
		init_pointer_array(pointer_array);
		show_pointer_array(pointer_array);
		clean_pointer_array(pointer_array);

		// 6. Ponteiro Duplo (int**)
		int** double_ptr_array = nullptr;
		init_double_ptr_array(&double_ptr_array);
		show_double_ptr_array(double_ptr_array);
		clean_double_ptr_array(double_ptr_array);

		// 7. C-String (array de caracteres)
		char c_string[] = "Exemplo de C-string";
		print_c_string(c_string);
	}

} // estatico
