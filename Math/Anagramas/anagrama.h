#pragma once
#include <iostream>
#include "defines.h"
#include "utils.h"
// next_permutation example
#include <algorithm>    // std::next_permutation, std::sort

namespace math {

	static vetorStr vt;
	// Anagrama=> Total de combinações possíveis de permutação das letras de uma dada palavra:
	static std::string _rotateL(std::string _s) {
		//P_(_s)
		int sz = _s.size();
		std::string s1=_s;
		for(int i2=0; i2<sz; i2++) {

			P_(s1)
			vt.push_back(s1);

			for(int i=0; i<sz-1; i++)
				s1[i]= _s[i+1];
			s1[sz-1] = _s[0];


			_s=s1;
		}
		return s1;
	}
	static void _permuta(std::string _s) {
		std::string ori=_s;
		
		for(int i=0; i<3; i++) {
			int sz = _s.size();
			while((--sz-1)) {
				_s = _rotateL(_s);
				//if(--sz)
				//_permuta(_s, sz-1);
				// swapping routine:
				//P_(_s)
				N
				char c=_s[sz-1];
				_s[sz-1]=_s[sz];
				_s[sz]=c;
				//if(--sz)
				//	_permuta(_s, sz);
			}
		}
			//_s="arom";
/*			while((--sz)-1) {
				_s = _rotateL(_s);
				N
				char c=_s[sz-1];
				_s[sz-1]=_s[sz];
				_s[sz]=c;
			}
			sz=4;
			while((--sz)-1) {
				_s = _rotateL(_s);
				N
				char c=_s[sz-1];
				_s[sz-1]=_s[sz];
				_s[sz]=c;
			}
			*/
	}

	static int _anagrama(const char *_s, bool _show=false) {
		int sz = strlen(_s);
		if(_show)
			for(int i=0; i<sz; i++)
				P_(_s[i])

		int sz2= sz;
		int res=1;
		// Fórmula: "c-a-b-e-l-o" =  6*5*4*3*2*1 = 720
		for(int i=0; i<sz; i++ )
			res *= sz2--;
		return res;
	}

	static void _indexes(const char *_str) {
		using namespace std;
		int base = strlen(_str);
		int total=0;
		for(int a=0; a<base; a++) {
	    	for(int b=0; b<base; b++) {
				if(b==a)
					continue;
				for(int c=0; c<base; c++) {
					if(c==a || c==b)
						continue;
					for(int d=0; d<base; d++) {
						if(d==a || d==b || d==c)
							continue;
						//cout << "[" << a << "][" << b << "][" << c << "][" << d << "]" << endl;
						//cout << a << b << c << d << endl;
						cout << _str[a] << _str[b] << _str[c] << _str[d] << endl;
						total++;
					} 
				}
			} N
		}
		P_(total)
	}
	static int _total=0;
	vetorInt v;
	void recursion(int depth, int maxDepth) {
		for(int i=0; i<maxDepth; i++) {
			//cout << string(depth - 1, '\t') << " i variable is " << i << endl;
			_total++;
			for(int a=1; a<maxDepth-1; a++) {
				if(depth==a){   //maxDepth-2) {
					if(depth==1) {
						v.clear();
						v.push_back(i);
						v.push_back(i);
					}
					v[a-1]=i;
				}
				if(depth==a+1) {//maxDepth-1) {
					v[a-1]=i;
				}
			}
			if(depth==maxDepth)
				std::cout << v[0] << v[1] << i << std::endl;
	
			//if(depth<maxDepth-1)
			//	cout << string(depth - 1, '\t') << "______" << i << endl;

			if(depth < maxDepth)
				recursion(depth + 1, maxDepth);
		}
	}
	class Loop {
		int m_size;
		int m_depth;
		int m_index;
		int m_value;
		int m_current;
		bool m_end;
		Loop *m_pointer;
	public:
		Loop(const int &_sz, int _dp):m_size(_sz), m_depth(_dp), m_index(0), m_value(0), m_current(0) {
			m_end=false;
			m_pointer=NULL;
			if(m_depth>=2)
				m_pointer=new Loop(_sz, m_depth-1);
			//start();
		}
		~Loop() { if(m_pointer) delete m_pointer; }
		void start() {
			m_value=0;
		}
		int getNext() {
			if(m_pointer)
				P_(m_pointer->getNext())
			//if(m_depth>=)
			if(m_current+1==m_size) m_end=true;
			if(m_current<m_size)
				return m_current++; 
			else {
				if(--m_depth>=2) {
					m_current=0; // rebobina
					return m_current;
				} else
					m_end=true;
			}
		}
		bool end() { return m_end; }
		Loop *getPtr() { return m_pointer; }
		int at(int index) {
		}
	};
	void _fool(const char *_str) {
		int len = strlen(_str);
		//std::vector<Loop> v;
		Loop l1(len, 2);

		//for(int i=0; i<len; i++) {
		while(!l1.end()) {
			P_(l1.getNext())
		}
	}
	// **************<<_USAGE_>>****************
	static void _anagramaUsage() {

		_fool("a");

//		recursion(1, 3);
//		P_(_total);
//		utils::_showVetor(v);
		//P_(_indexes2(3))
		//_indexes("amor");
		N
		//_permuta("amor");
		//sort(vt.begin(), vt.end());
		//utils::_showVetor(vt);
		//P_(_anagrama("ato"))
	}

} // math