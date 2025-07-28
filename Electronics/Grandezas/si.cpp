#include "SI.h"

typedef enum multi { yocto=-8,
		  zepto,
		  atto,	
		  femto,
		  pico,	
		  nano,	
		  micro,
		  milli,	
		  //centi
		  //deci
		  um,	
		  //deca
		  //hecta
		  quilo,
		  mega,	
		  giga,	
		  tera,	
		  peta,	
		  exa,	
		  zeta,
		  yota
} pliers;

char* prefixes[17][2] = {
	"yocto"   ,"y", // 10^-24
	"zepto"   ,"z", // 10^-21
	"atto"	  ,"a", // 10^-18
	"femto"   ,"f", // 10^-15
	"pico"	  ,"p", // 10^-12
	"nano"	  ,"n", // 10^-9 
	"micro"   ,"u", // 10^-6 
	"mili"	  ,"m", // 10^-3 
	//"centi" ,"c", // 10^-2 
	//"deci"  ,"d", // 10^-1
	"um"	  ,"-", // 10^0
	//"deca"  ,"da", // 10^1
	//"hecto" ,"h", // 10^2
	"quilo "  ,"k", // 10^3  
	"mega"	  ,"M", // 10^6  
	"giga"	  ,"G", // 10^9  
	"tera"	  ,"T", // 10^12 
	"peta"	  ,"P", // 10^15 
	"exa"	  ,"E", // 10^18 
	"zeta"	  ,"Z", // 10^21 
	"yotta"	  ,"Y"  // 10^24 
};

void elect::_testIndexes() {
	pliers p=yocto;
	for(int i=p; i<=yota; i++) {
		std::cout << prefixes[i+8][0] << " :" << i << " - ";
		std::cout << prefixes[i+8][1] << std::endl;
	}
}