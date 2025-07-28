#include <iostream>
#include <vector>
#include <utility> // Para std::pair
#include <unordered_map> // Para usar um mapa não ordenado para contar elementos únicos
#include "..\..\Utilidades\Utilidades\_random.h"

std::vector<std::pair<int, int>> countVector(const std::vector<int>& vetor) {
    std::vector<std::pair<int, int>> accumulatedCounts;

	std::unordered_map<int, int> countMap; // Mapa para contar elementos únicos
	int totalCount = 0;

	// Contagem de elementos únicos e total de elementos
	//for (int num : vetor) {
	for(unsigned int i = 0; i < vetor.size(); i++) {
		int num2 = vetor[i];
		countMap[num2]++;
		totalCount++;

	     // Atualizar o vetor de acumulado para cada número encontrado
        accumulatedCounts.emplace_back(num2, totalCount);
	}

	return accumulatedCounts;
}

int countVectorUsage() {
	std::vector<int> vetor;// = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; // Exemplo de vetor
	for(int i=0; i<10; i++) {
		vetor.push_back((int)utils::_random(0,5));
	}
	utils::_showVetor(vetor);
	// Chamada da função para contar elementos
	std::pair<int, int> counts = countVector(vetor);

	std::vector<std::pair<int, int>> accumulatedCounts = countVector(vetor);

	// Imprimir o acumulado para cada número
//	for (const auto& pair : accumulatedCounts) {
//		std::cout << "Número: " << pair.first << ", Acumulado: " << pair.second << std::endl;
//	}

	system("pause");
	return 0;
}
