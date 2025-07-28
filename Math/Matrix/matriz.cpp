#include "matriz.h"
#include "utils.h"

// BI-Dimensional Matrizes: (linha, coluna):
// Construtor padrão:

namespace math {
	using std::cout;
	using std::endl;

	Matriz::Matriz():m_x(0), m_y(1), arr(NULL) { } //DS_("Matriz()...") /*utils::require()*/ } 

	Matriz::Matriz(const int &_x, const int &_y): m_x(_x), m_y(_y) {
		arr = new int[m_x * m_y];
		// Initializing array to 0:
		for (int i = 0; i < _x; i++)
			for (int j = 0; j < _y; j++)
				*(arr + i * _y + j) = 0; // Assign values to

	} //DS_("Frame(const int, const int)...") /*utils::require()*/ } 

	void Matriz::Print() {
		// Traverse the 2D array
		for (int i = 0; i < m_x; i++) {
			std::cout << "| ";
			for (int j = 0; j < m_y; j++)
				std::cout << *(arr + i * m_y + j) << ", ";
			std::cout << "|" << std::endl;
		}
	}

	void Matriz::fill(int _n,...) {

		va_list args;
		va_start(args, _n); // initialize argptr
		for (int x=0; x<m_x; x++)     // linha
			for (int y=0; y<m_y; y++) // coluna
				*(arr + x * m_y + y) = va_arg(args, int);

		va_end(args);

	}
	// **************<<_USAGE_>>****************
	void _matrizUsage() {
		int line   = 3;
		int column = 4;
		math::Matriz m1(line, column);

		m1.fill(line*column, 1, 2, 3, 4,
			5, 6, 7, 8,
			9, 10,11,12);
		m1.Print();
	}
};