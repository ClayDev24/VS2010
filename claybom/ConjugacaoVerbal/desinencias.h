// Desin�ncias:
// MODO INDICATIVO (indica uma afirma��o)
namespace indicativo { // Desin�ncias modo-temporais do indicativo
	//Os verbos da l�ngua portuguesa pertencem � 3 conjuta��es: Verbos terminados em...
	// ar=> 1 conjuga��o. Ex.: Estudar
	// er=> 2 conjuga��o. Ex.: Vender
	// ir=> 3 conjuga��o. Ex.: Partir
	static const char *presente[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
		/* Eu  */ "canto",	  "vendo",    "parto",    // o    o    o  
		/* Tu  */ "cantas",   "vendes",   "partes",   // as   es   es
		/* Ele */ "canta",	  "vende",    "parte",    // a    e    e
		/* N�s */ "cantamos", "vendemos", "partimos", // amos emos imos
		/* V�s */ "cantais",  "vendeis",  "partis",   // ais  eis  is
		/* Eles*/ "cantam",   "vendem",   "partem"    // am   em   em
	};
	namespace preterito {
		static const char *perfeito[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
			/* Eu  */ "cantei",	  "vendi",	  "parti",	 // ei    i     i
			/* Tu  */ "cantaste", "vendeste", "partiste", // aste  este  iste
			/* Ele */ "cantou",	  "vendeu",	  "partiu",	 // ou    eu    iu 
			/* N�s */ "cantamos", "vendemos", "partimos", // amos  emos  imos
			/* V�s */ "cantastes","vendestes","partistes",// astes estes istes
			/* Eles*/ "cantaram", "venderam", "partiram"	 // aram  eram  iram
		};
		static const char *imperfeito[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
			/* Eu  */ "cantava",   "vendia",	"partia",	// ava    ia    ia
			/* Tu  */ "cantavas",  "vendias",	"partias",	// ava    ias   ias
			/* Ele */ "cantava",   "vendia",	"partia",	// ava    ia    ia
			/* N�s */ "cant�vamos","vend�amos", "part�amos",// �vamos �amos �amos
			/* V�s */ "cant�veis", "vend�eis",	"part�eis",	// �veis  �eis  �eis
			/* Eles*/ "cant�vam",  "vendiam",	"partiam"	// �vam   iam   iam
		};
		static const char *mais_que_perfeito[6][3] = {
			/* Eu  */ "cantara",	"vendera",	 "partira",	  // ara    era    ira
			/* Tu  */ "cantaras",	"venderas",	 "partiras",  // aras   eras   iras
			/* Ele */ "cantara",	"vendera",	 "partira",	  // ara    era    ira
			/* N�s */ "cant�ramos", "vend�ramos","part�ramos",// �ramos �ramos �ramos
			/* V�s */ "cant�reis",	"vend�reis", "part�reis", // �reis  �reis  �reis
			/* Eles*/ "cantaramos", "venderam",	 "partiram"	  // aramos eram   iram
		};
	};

	namespace futuro {
		static const char *doPresente[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
			/* Eu  */ "cantarei",	"venderei",	 "partirei", // arei   erei   irei
			/* Tu  */ "cantar�s",	"vender�s",	 "partir�s", // ar�s   ar�s   ir�s
			/* Ele */ "cantar�",	"vender�",	 "partir�",	 // ar�    er�    ir�
			/* N�s */ "cantaremos","venderemos", "artiremos",// aremos eremos iremos
			/* V�s */ "cantareis",	"vendereis", "partireis",// areis  ereis  ireis
			/* Eles*/ "cantar�o",	"vender�o",	 "partir�o"	 // ar�o   er�o   ir�o
		};
		static const char *doPreterito[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
			/* Eu  */ "cantaria",	 "venderia",   "partiria",	 // aria    eria    iria
			/* Tu  */ "cantarias",	 "venderias",  "partirias",	 // arias   erias   irias
			/* Ele */ "cantaria",	 "venderia",   "partiria",	 // eria    eria    iria
			/* N�s */ "cantar�amos", "vender�amos","partir�amos",// ar�amos er�amos ir�amos
			/* V�s */ "cantar�eis",  "vender�eis", "partir�eis", // ar�eis  er�eis  ir�eis
			/* Eles*/ "cantariam",	 "venderiam",  "partiriam"	 // ariam   eriam   iriam
		};
	};

};
// MODO SUBJUNTIVO (indica incerteza)
namespace subjuntivo {

	static const char *presente[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
		/* 'que' eu  */ "cante",	"venda",    "parta",   // e    a    a 
		/* 'que' tu  */ "cantes",	"vendas",   "partas",  // es   as   as
		/* 'que' ele */ "cante",	"venda",    "parta",   // e    a    a
		/* 'que' n�s */ "cantemos", "vendamos", "partamos",// emos amos amos
		/* 'que' v�s */ "canteis",	"vendais",  "partais", // eis  ais  ais
		/* 'que' eles*/ "cantem",	"vendam",   "partam"   // em   am   am
	};
	static const char *preterito_imperfeito[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
		/* 'se' eu  */ "cantasse",	  "vendesse",   "partisse",   // asse    esse    isse
		/* 'se' tu  */ "cantasses",   "vendesses",  "partisses",  // asses   esses   isses
		/* 'se' ele */ "cantasse",	  "vendesse",   "partisse",   // asse    esse    isse
		/* 'se' n�s */ "cant�ssemos", "vend�ssemos","part�ssemos",// �ssemos �ssemos �ssemos
		/* 'se' v�s */ "cant�sseis",  "vend�sseis", "part�sseis", // �sseis  �sseis  �sseis
		/* 'se' eles*/ "cantassem",   "vendessem",  "partissem"	  // assem   essem   issem
	};
	static const char *futuro[6][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
		/* 'quando' eu  */ "cantar",	"vender",    "partir",	 // ar    er    ir
		/* 'quando' tu  */ "cantares",  "venderes",  "partires", // ares  eres  ires
		/* 'quando' ele */ "cantar",	"vender",    "partir",	 // ar    er    ir
		/* 'quando' n�s */ "cantarmos", "vendermos", "partirmos",// armos ermos irmos
		/* 'quando' v�s */ "cantardes", "venderdes", "partirdes",// ardes erdes irdes
		/* 'quando' eles*/ "cantarem",	"venderem",  "partirem"	 // arem  erem  irem
	};

};
// MODO IMPERATIVO (indica uma ordem / pedido / desejo)
namespace imperativo { 
	static const char *afirmativo[5][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
		
		/* Tu   */ "canta",   "vende",   "parti",   // a    e    i
		/* Ele  */ "cante",   "venda",   "parta",   // e    a    a
		/* N�s  */ "cantemos","vendamos","partamos",// emos amos amos
		/* V�s  */ "cantai",  "vendei",  "parti",   // ai   ei   i
		/* Eles */ "cantem",  "vendam",  "partam"   // em   am   am
	};
	static const char *negativo[5][3] = { // 1 / 2 / 3 conjuga��es (ar-er-ir)
		
		/* Tu   n�o */ "cantes",  "vendas",  "partas",  // es   as   as
		/* Ele  n�o */ "cante",   "venda",   "parta",   // e    a    a
		/* N�s  n�o */ "cantemos","vendamos","partamos",// emos amos amos
		/* V�s  n�o */ "canteis", "vendais", "partais", // eis  ais  ais
		/* Eles n�o */ "cantem",  "vendam",  "partam"   // em   am   am
	};
};

// FORMAS NOMINAIS=> Aquelas em que os verbos se comportam como nomes. (n�o h� varia��o de modo e tempo)
static const char *infinitivoPessoal[6][3] = { // o infinitivo acompanha a mesma forma do futuro do subjuntivo
	/* por */"cantar",	 "vender",    "partir",	  /* eu  */
	/* por */"cantares", "venderes",  "partires", /* tu  */ 
	/* por */"cantar",	 "vender",    "partir",	  /* ele */
	/* por */"cantarmos","vendermos", "partirmos",/* n�s */ 
	/* por */"cantardes","venderdes", "partirdes",/* v�s */ 
	/* por */"cantarem", "venderem",  "partirem"  /* eles*/
};
