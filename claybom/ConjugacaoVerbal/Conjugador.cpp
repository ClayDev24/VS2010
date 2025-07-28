#include "Conjugador.h"
#include "desinencias.h"
#include "utils.h"
#include "..\..\Utilidades\Console\graphical.h"

void clb::Conjugador::start() {
	int len = strlen(m_verb.c_str());
	std::string final = m_verb.substr(len-2, len);
	if(final=="ar")
		m_conjugacao=0;
	else if(final=="er")
		m_conjugacao=1;
	else if(final=="ir")
		m_conjugacao=2;
}

void clb::Conjugador::conjugar(const char *_modo[6][3]) {
	using namespace std;
	int len = strlen(m_verb.c_str());
	string sufixo, str, prefixo = m_verb.substr(0, len-2);

	for(int i=0; i<6; i++) {
		str  = _modo[i][m_conjugacao];
		len   = strlen(str.c_str());
		sufixo = str.substr(4, len-4);
		cout << prefixo+sufixo << endl;
	} N
}

void clb::Conjugador::conjugarTodos() {
	using namespace std;
	int len = strlen(m_verb.c_str());
	string prefixo = m_verb.substr(0, len-2);

	utils::PrintColour_("<<_Forma Impessoal_>>\n\n", FGI);

	utils::PrintColour_("<<_Presente do Indicativo_>>\n\n", FGI);
	
	utils::PrintColour_("<<_Pretérito Perfeito do Indicativo_>>\n\n", FGI);

	utils::PrintColour_("<<_Pretérito Imperfeito do Indicativo_>>\n\n", FGI);

	utils::PrintColour_("<<_Pretérito Mais que Perfeito do Indicativo_>>\n\n", FGI);

	utils::PrintColour_("<<_Presente do Subjuntivo_>>\n\n", FGI);

	utils::PrintColour_("<<_Pretérito Imperfeito do Subjuntivo_>>\n\n", FGI);

	utils::PrintColour_("<<_Futuro do Subjuntivo_>>\n\n", FGI);

	utils::PrintColour_("<<_Imperativo Afirmativo_>>\n\n", FGI);

	utils::PrintColour_("<<_Imperativo Negativo_>>\n\n", FGI);

	utils::PrintColour_("<<_Infinitivo_Pessoal_>>\n\n", FGI);
		
	utils::PrintColour_("<<_Infinitivo_IMPESSOAL_>>\n\n", FGI);
	cout << "O infinitivo indica a ação em si mesma: Ler é muito útil.\n\n";
	P_(m_verb)

	utils::PrintColour_("<<_Gerúndio_>>\n\n", FGI);
	prefixo = m_verb.substr(0, len-3);
	cout << prefixo+"ndo" << endl;
}

void clb::_conjugadorUsage() {
	using namespace std;
	utils::Graphical janela(220, 500, "Graphical Console"); // COLUNA X LINHA
	

	janela.setColour(FRI|BBI);
//	janela.canvas(' ', BYI, 1,  1, 118, 47);
//	janela.canvas(' ', BWI, 11, 17, 34, 29);
//	janela.box("Indicativo",10, 16, 35, 30);
//	janela.canvas(' ', BWI, 67, 17, 76, 17);
//	janela.box(       "bbb",66, 16, 77, 18);

//	janela.box("Copnjugador Verbal", 0, 0, 119, 48);

	janela.setColour(FGI);

	//janela.write2Console("<<_Presente do Indicativo_>>",10,2,FBI);
	//TAB utils::PrintColour_("<<_CONJUGADOR VERBAL_>>\n\n", FRI);

	Conjugador verbo("caminhar");
	verbo.conjuga(indicativo::presente);
	verbo.conjuga(indicativo::preterito::perfeito);
	verbo.conjuga(indicativo::preterito::imperfeito);
	verbo.conjuga(indicativo::preterito::mais_que_perfeito);
	verbo.conjuga(subjuntivo::presente);
	verbo.conjuga(subjuntivo::preterito_imperfeito);
	verbo.conjuga(subjuntivo::futuro);
	verbo.conjuga(imperativo::afirmativo);
	verbo.conjuga(imperativo::afirmativo);
	verbo.conjuga(imperativo::negativo);
	verbo.conjuga(infinitivoPessoal);

	verbo.conjugarTodos();

	//janela.prtColorReturn(verbo, FRI); N

}
