// Desinências:
// MODO INDICATIVO (indica uma afirmação)
namespace indicativo { // Desinências modo-temporais do indicativo
	//Os verbos da língua portuguesa pertencem à 3 conjutações: Verbos terminados em...
	// ar=> 1 conjugação. Ex.: Estudar
	// er=> 2 conjugação. Ex.: Vender
	// ir=> 3 conjugação. Ex.: Partir
	static const char *presente[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
		/* Eu  */ "canto",	  "vendo",    "parto",    // o    o    o  
		/* Tu  */ "cantas",   "vendes",   "partes",   // as   es   es
		/* Ele */ "canta",	  "vende",    "parte",    // a    e    e
		/* Nós */ "cantamos", "vendemos", "partimos", // amos emos imos
		/* Vós */ "cantais",  "vendeis",  "partis",   // ais  eis  is
		/* Eles*/ "cantam",   "vendem",   "partem"    // am   em   em
	};
	namespace preterito {
		static const char *perfeito[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
			/* Eu  */ "cantei",	  "vendi",	  "parti",	 // ei    i     i
			/* Tu  */ "cantaste", "vendeste", "partiste", // aste  este  iste
			/* Ele */ "cantou",	  "vendeu",	  "partiu",	 // ou    eu    iu 
			/* Nós */ "cantamos", "vendemos", "partimos", // amos  emos  imos
			/* Vós */ "cantastes","vendestes","partistes",// astes estes istes
			/* Eles*/ "cantaram", "venderam", "partiram"	 // aram  eram  iram
		};
		static const char *imperfeito[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
			/* Eu  */ "cantava",   "vendia",	"partia",	// ava    ia    ia
			/* Tu  */ "cantavas",  "vendias",	"partias",	// ava    ias   ias
			/* Ele */ "cantava",   "vendia",	"partia",	// ava    ia    ia
			/* Nós */ "cantávamos","vendíamos", "partíamos",// ávamos íamos íamos
			/* Vós */ "cantáveis", "vendíeis",	"partíeis",	// áveis  íeis  íeis
			/* Eles*/ "cantávam",  "vendiam",	"partiam"	// ávam   iam   iam
		};
		static const char *mais_que_perfeito[6][3] = {
			/* Eu  */ "cantara",	"vendera",	 "partira",	  // ara    era    ira
			/* Tu  */ "cantaras",	"venderas",	 "partiras",  // aras   eras   iras
			/* Ele */ "cantara",	"vendera",	 "partira",	  // ara    era    ira
			/* Nós */ "cantáramos", "vendêramos","partíramos",// áramos êramos íramos
			/* Vós */ "cantáreis",	"vendêreis", "partíreis", // áreis  êreis  íreis
			/* Eles*/ "cantaramos", "venderam",	 "partiram"	  // aramos eram   iram
		};
	};

	namespace futuro {
		static const char *doPresente[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
			/* Eu  */ "cantarei",	"venderei",	 "partirei", // arei   erei   irei
			/* Tu  */ "cantarás",	"venderás",	 "partirás", // arás   arás   irás
			/* Ele */ "cantará",	"venderá",	 "partirá",	 // ará    erá    irá
			/* Nós */ "cantaremos","venderemos", "artiremos",// aremos eremos iremos
			/* Vós */ "cantareis",	"vendereis", "partireis",// areis  ereis  ireis
			/* Eles*/ "cantarão",	"venderão",	 "partirão"	 // arão   erão   irão
		};
		static const char *doPreterito[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
			/* Eu  */ "cantaria",	 "venderia",   "partiria",	 // aria    eria    iria
			/* Tu  */ "cantarias",	 "venderias",  "partirias",	 // arias   erias   irias
			/* Ele */ "cantaria",	 "venderia",   "partiria",	 // eria    eria    iria
			/* Nós */ "cantaríamos", "venderíamos","partiríamos",// aríamos eríamos iríamos
			/* Vós */ "cantaríeis",  "venderíeis", "partiríeis", // aríeis  eríeis  iríeis
			/* Eles*/ "cantariam",	 "venderiam",  "partiriam"	 // ariam   eriam   iriam
		};
	};

};
// MODO SUBJUNTIVO (indica incerteza)
namespace subjuntivo {

	static const char *presente[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
		/* 'que' eu  */ "cante",	"venda",    "parta",   // e    a    a 
		/* 'que' tu  */ "cantes",	"vendas",   "partas",  // es   as   as
		/* 'que' ele */ "cante",	"venda",    "parta",   // e    a    a
		/* 'que' nós */ "cantemos", "vendamos", "partamos",// emos amos amos
		/* 'que' vós */ "canteis",	"vendais",  "partais", // eis  ais  ais
		/* 'que' eles*/ "cantem",	"vendam",   "partam"   // em   am   am
	};
	static const char *preterito_imperfeito[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
		/* 'se' eu  */ "cantasse",	  "vendesse",   "partisse",   // asse    esse    isse
		/* 'se' tu  */ "cantasses",   "vendesses",  "partisses",  // asses   esses   isses
		/* 'se' ele */ "cantasse",	  "vendesse",   "partisse",   // asse    esse    isse
		/* 'se' nós */ "cantássemos", "vendêssemos","partíssemos",// ássemos êssemos íssemos
		/* 'se' vós */ "cantásseis",  "vendêsseis", "partísseis", // ásseis  ísseis  ísseis
		/* 'se' eles*/ "cantassem",   "vendessem",  "partissem"	  // assem   essem   issem
	};
	static const char *futuro[6][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
		/* 'quando' eu  */ "cantar",	"vender",    "partir",	 // ar    er    ir
		/* 'quando' tu  */ "cantares",  "venderes",  "partires", // ares  eres  ires
		/* 'quando' ele */ "cantar",	"vender",    "partir",	 // ar    er    ir
		/* 'quando' nós */ "cantarmos", "vendermos", "partirmos",// armos ermos irmos
		/* 'quando' vós */ "cantardes", "venderdes", "partirdes",// ardes erdes irdes
		/* 'quando' eles*/ "cantarem",	"venderem",  "partirem"	 // arem  erem  irem
	};

};
// MODO IMPERATIVO (indica uma ordem / pedido / desejo)
namespace imperativo { 
	static const char *afirmativo[5][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
		
		/* Tu   */ "canta",   "vende",   "parti",   // a    e    i
		/* Ele  */ "cante",   "venda",   "parta",   // e    a    a
		/* Nós  */ "cantemos","vendamos","partamos",// emos amos amos
		/* Vós  */ "cantai",  "vendei",  "parti",   // ai   ei   i
		/* Eles */ "cantem",  "vendam",  "partam"   // em   am   am
	};
	static const char *negativo[5][3] = { // 1 / 2 / 3 conjugações (ar-er-ir)
		
		/* Tu   não */ "cantes",  "vendas",  "partas",  // es   as   as
		/* Ele  não */ "cante",   "venda",   "parta",   // e    a    a
		/* Nós  não */ "cantemos","vendamos","partamos",// emos amos amos
		/* Vós  não */ "canteis", "vendais", "partais", // eis  ais  ais
		/* Eles não */ "cantem",  "vendam",  "partam"   // em   am   am
	};
};

// FORMAS NOMINAIS=> Aquelas em que os verbos se comportam como nomes. (não há variação de modo e tempo)
static const char *infinitivoPessoal[6][3] = { // o infinitivo acompanha a mesma forma do futuro do subjuntivo
	/* por */"cantar",	 "vender",    "partir",	  /* eu  */
	/* por */"cantares", "venderes",  "partires", /* tu  */ 
	/* por */"cantar",	 "vender",    "partir",	  /* ele */
	/* por */"cantarmos","vendermos", "partirmos",/* nós */ 
	/* por */"cantardes","venderdes", "partirdes",/* vós */ 
	/* por */"cantarem", "venderem",  "partirem"  /* eles*/
};
