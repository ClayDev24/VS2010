#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <initializer_list>

namespace math {

	class Statistics {
	private:
		std::vector<double> m_valores;
		double m_moda{0};
		double m_media{0};
		double m_mediana{0};
		double m_desvioPadrao{0};

	public:
		Statistics(std::initializer_list<double> valores) : m_valores(valores) {
			std::sort(m_valores.begin(), m_valores.end());
		}

		double getModa() {
			std::map<double, int> freq;
			for (double val : m_valores)
				++freq[val];

			int maxFreq = 0;
			for (const auto& [valor, f] : freq)
				if (f > maxFreq) {
					maxFreq = f;
					m_moda = valor;
				}

				return m_moda;
		}

		double getMedia() {
			m_media = std::accumulate(m_valores.begin(), m_valores.end(), 0.0) / m_valores.size();
			return m_media;
		}

		double getMediana() {
			size_t sz = m_valores.size();
			if (sz % 2 == 1)
				m_mediana = m_valores[sz / 2];
			else
				m_mediana = (m_valores[sz / 2 - 1] + m_valores[sz / 2]) / 2;
			return m_mediana;
		}

		double getDesvioPadrao() {
			double media = getMedia();
			double soma = 0.0;
			for (double val : m_valores)
				soma += std::pow(val - media, 2);
			m_desvioPadrao = std::sqrt(soma / m_valores.size());
			return m_desvioPadrao;
		}

		void imprimir() const {
			std::cout << "Valores: ";
			for (double val : m_valores)
				std::cout << val << " ";
			std::cout << "\n";
		}
	};

	// Exemplo de uso
	void statisticsUsage() {
		Statistics s1{2.0, 2.0, 11.0, 4.0, 7.0, 3.0, 3.0, 5.0, 5.0, 5.0};
		s1.imprimir();

		std::cout << "Moda: " << s1.getModa() << "\n";
		std::cout << "Média: " << s1.getMedia() << "\n";
		std::cout << "Mediana: " << s1.getMediana() << "\n";
		std::cout << "Desvio padrão: " << s1.getDesvioPadrao() << "\n";
	}

} // namespace math
