//#include "vld.h"
#include <iostream>
//#include "defines.h"

// Accessors & mutators with "get" and "set"
class Rectangle {
	int width, height;
public:
	Rectangle(const int &_w=0, const int &_h=0):width(_w), height(_h) {}
	inline int  getWidth() const          { return width;  } //accessor
	inline void setWidth(const int &_w)   { width  = _w;   } //mutator
	inline int  getHeight() const         { return height; } //accessor
	inline void setHeight(const int &_h)  { height = _h;   } //mutator
};

int main() {
	Rectangle r(19, 47);
	// Change width & height:
	r.setHeight(r.getWidth());
	r.setWidth(r.getHeight());

	system("pause");
	return(0);
}
