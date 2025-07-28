#include "include_all.h"
#include "constants.h"
// Perímetro=> Medida da linha de contorno de uma figura geométrica.
namespace perimetro {

	// Perímetro de um polígono é a soma das medidas de seus lados:
	double polygon(int num,...) {
		double sum = 0.0;

		va_list args;
		va_start(args, num); // initialize argptr
		while(num--) {		 // sum the parameters
			double f = va_arg(args, double);
			sum += f;
		}
		va_end(args);

		return sum;
	}
	// Retângulo: A = c * l (Area / comprimento / largura)
	float rectangle(const float &_comprimento, const float &_altura) {
		return ((_comprimento*2) + (_altura*2));
	}
	float square(const float &_lado) {
		return _lado*4;
	}
	// Perímetro do círculo=> Comprimento da circunferência (área de contorno arredondada)
	// C = D*Pi (Comprimento = Diâmetro(2*raio) x Pi)
	float circulo(const float &_diametro) {
		return _diametro * Pi;
	}
}
// Área=> Medida de uma superfície (piso, lousa, parede, etc). Medida em (m)etros
// Área de figuras planas:

namespace area {

	// Retângulo=> A = c * l (área / comprimento / largura)
	float rectangle(const float &Comprimento, const float &Largura) {
		float area = Comprimento * Largura;
		return area;
	}
	// Quadrado => A = l^2   (área / largura)
	float square(const float &Largura) {
		float area = Largura * Largura;
		return area;
	}
	// Triângulo=> A = (b*h)/2 (área / base / altura(perpendicular à base
	float triangle(const float &Altura, const float &Base) {
		float area = (Altura * Base) / 2;
		return area;
	}
	// Trapézio => A = ((B + b)*h)/2  (área / base maior / base menor / altura do trapézio
	float trapezio(const float&BaseMaior, const float &BaseMenor, const float &Altura) {
		float area = ((BaseMaior + BaseMenor) * Altura) / 2;
		return area;
	}


}

void _calculos() {
	P_(perimetro::polygon(6, 12.5,12.5,12.5,12.5,12.5,12.5))
	P_(perimetro::rectangle(13.5f,10.8f))
	P_(perimetro::square(7))
	P_(perimetro::circulo(20))

	P_(area::rectangle(6, 4))
	P_(area::square(3.5))
	P_(area::triangle(30,24))
	P_(area::trapezio(7,4,2.6f))

}