#include <conio.h> // getche()
#include <iostream>
#include "console.h"
using namespace std;
using namespace clb;

int main() {

	Console dos; // Ycolumns, Xlines
	//dos.title("DOS Window");
	//dos.paint(BWI, true);
	getche();
	dos.size(120,70);
	dos.cls();
	//dos.canvas (0,0,49,39, BYI);
//	dos.canvas (1,1,49,39, BRI);
//	dos.outline(0,0,49,39, "ola");
//	dos.button (1,1,20,5,BCI); // left, top, right, bottom
//	dos.size(15, 15);
//	dos.cursor(50);
//	dos.gotoxy(10, 20); // column x line
//	dos.colour(FRI|BG);
	dos.cls(0, 0, 'x');

//	dos.printBuf(1,2, "clailton", FW|BMI);
//	dos.outlineBuf(0,0,49,39, "outline", FCI|BNULL);
	
//	dos.gotoxy(10,5);
//	dos.colour(BNULL|FGI);

/*	clb::Console danishFlag(40, 20);
	danishFlag.title("Bandeira Dinamarca");
	danishFlag.canvas(0,0,39,19, BRI);
	danishFlag.canvas(0,9,39,11, BWI);
	danishFlag.canvas(12,0,16,19, BWI);
*/
	getche();
	return 0;
}