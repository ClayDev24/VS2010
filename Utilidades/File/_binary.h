#include <iostream>
#include <fstream>
#define SIZE 5000
#define TYPE float

namespace utils {

	static int _binary(char *_file) {
		using namespace std;
		ifstream in;  // Open for reading
		ofstream out; // Open for writing

		float  pi = static_cast<float>(3.14);
		double d  = 2.3456;
		//string file("file.txt");//
		out.open(_file);//"file.txt");//file.c_str());
		if(!out) {
			cout << "File " << _file << " not open for write" << endl;
			return(1);
		}
		out << pi << endl << d;
		out.close();

		ifstream in2("file.txt");
		in2.open("file.txt");//file.c_str());
		if(!in2) {
			cout << "File " << _file << " not open for read" << endl;
			//return(1);
		}
		in2 >> pi >> d;
		cout.setf(ios::dec);
		cout << "pi = " << pi << endl
			 << "d  = " << d  << endl;
		in2.close();

		// TEXT X BINARIO:

		TYPE v[SIZE];
		int i;
		for(i=0; i < SIZE; i++)
			v[i] = static_cast<float>(i+0.123);
		// grava o arquivo em binário
		ofstream myfile;
		char* fname = "f_bin.txt";
		myfile.open(fname, ios::binary);
		if(!myfile)
			cout << "File " << fname << " not open" << endl;
		// para gravar um por um dos elementos do vetor
		for(i=0; i < SIZE; i++)
			myfile.write((const char*)&v[i],sizeof(TYPE));
		// para gravar o vetor todo de uma vez
		// myfile.write((unsigned char*)&vetor[0],SIZE*sizeof(TYPE));
		myfile.close();
		// grava o arquivo em forma de texto
		fname = "f_txt.txt";
		myfile.open(fname);
		if(!myfile)
			cout << "File " << fname << " not open";
		for(i=0 ; i<SIZE ; i++)
			myfile << v[i] << endl;
		myfile.close();

		//LER BINARIO:
		ifstream myfile2;
		myfile2.open(fname);
		if(!myfile2)
			cout << "File " << fname << " not open" << endl;
		myfile2.read((char*)&v,sizeof(float));
		myfile2.close();

		for(i=0; i<SIZE; i++)
			cout << v[i] << endl;
		// para ler um por um dos elementos do vetor
		// for (i=0 ; i<SIZE ; i++)
		// myfile.read((unsigned char*)&vetor[i],sizeof(TYPE));

		// lê o arquivo em forma de texto
		fname = "f_txt.dat";
		myfile2.open(fname);
		if(!myfile2)
			cout << "File " << fname << " not open";
		// Lê um por um os elementos do vetor
		for(i=0; i<SIZE; i++)
			myfile2 >> v[i];
		myfile2.close();
		for(i=0; i<SIZE; i++)
			cout << v[i] << endl;

		return(1);
	}
	// **************<<_USAGE_>>****************
	static void _binaryUsage() {
		_binary("file.txt");
	}

} // utils