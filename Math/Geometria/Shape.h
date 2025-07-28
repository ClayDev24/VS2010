#pragma once
#include <iostream>
#include <string>
#include "defines.h"

namespace math {

	class Shape {
		std::string label;
	public:
		Shape():label("Shape.jpg") {DS("Shape()...")};
		~Shape() {DS("~Shape()...")};
		void show() {
			std::string s("I:\\Resumos\\Math\\Imagens\\");
			s.append(label);
			//P_(s)
			system(s.c_str());
		}
	};

} // math