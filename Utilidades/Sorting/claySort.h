#include <iostream>
#include <vector>

namespace utils {

	class ClaySort {
		int *arr;
		int m_size;
	public: 
		ClaySort() {};
		ClaySort(int ar[], const int &_size):m_size(_size) {
			arr = ar;
		}
		int* ordena() {
			int candidato = 0;
			int vigente   = 0;
			int counter   = 0;
			bool eh = false;
			while(true) {
				eh = false;
				for(int i=counter; i<m_size; i++) {
					if(arr[i] < arr[candidato]) {
						vigente   = i;
						candidato = vigente;
						eh = true;
					}
				}
				if(eh)
					troca(vigente, counter);
				counter++;
				vigente   = counter;
				candidato = counter;
				if(counter == (m_size - 1)) break;
			}//while  
			return arr;
		}	//metodo
		void troca(const int &_i1, const int &_i2) {
			int temp = arr[_i1];
			arr[_i1] = arr[_i2];
			arr[_i2] = temp;
		}
	};
	// Usage:
	static void claySortUsage() {
		using namespace std;

		const int max = 10;
		int ar[max];
		int num;
		for(int i=0; i<max; i++) {  	
			cout << "Entre um numero: ";
			cin >> num; 
			ar[i] = num;
		}

		ClaySort *cs = new ClaySort(ar, max);
		int *vt = cs->ordena();

		for(int i=0; i<max; i++)
			cout << ar[i] << endl;

		delete cs;
	};

} // utils