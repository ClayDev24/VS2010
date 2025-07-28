#include <string>
#include "Pairint.h"
#include "Tokenizer.h"
#include "Article.h"

#define operador LessThan

typedef std::vector<std::string> vtStr;
typedef std::vector<CArticle*>   vtMsg;
typedef std::vector<CPairInt*>   vtPairInt;
typedef std::vector<CPair*>      vtPair;

class IntCompare:std::binary_function<CPairInt, CPairInt, bool> {
  public:
	bool operator() (CPairInt *a, CPairInt *b) {
	  return (a->operador(b));
	}
};

class NameCompare:std::binary_function<CPair, CPair, bool> {
  public:
	bool operator() (CPair *a, CPair *b) {
	  return (a->operador(b));
	}
};

class CStatistics {
public:
	CStatistics();
	virtual ~CStatistics();
    int m_totalNickname;
    int m_totalNickEmail;
    int m_totalNews;
    int m_totalMsgs;
    int m_totalXreader;
    int m_totalNovos;
    int m_totalX_Msgs;
	int m_totalGroups;
    int m_totalX_Groups;
    int m_totalReplys;
    int m_totalIps;
    int m_totalSubject;

	std::string m_selected_ng;
	std::string m_subject;
	std::string m_period;

	bool m_view;
	bool m_selection;
	bool m_dayly;
	int  m_mode;

    bool is_empty(void);
    std::string show(unsigned int header, std::string kind);
    std::string retorna_ngs_geral(void);
    std::string pesquisa_pseudo(const std::string &nick);
	std::string advanced_search(const std::string &nick, int header);
	std::string top_happen(int qts, unsigned int header);
	std::string postagem(const std::string &s);
	std::string modelo1(const int &Quantity);
	std::string pico(void);
    vtPairInt* retorna_ngs_inscritos(const std::string &nick, const int &hdr);	  	
	vtStr     top_happen_key(int qts, unsigned int header);
	void     readFile(std::string file_name);
	void     define_partial(void);	

private:
	vtMsg *vArticlesGeral;
	vtMsg *vArticlesPartial;
	vtPairInt *vVigent;
  	vtPairInt *vIp;
  	vtPairInt *vHour;
  	vtPairInt *vGroups;
  	vtPairInt *vCross;
  	vtPairInt *vNickname;
  	vtPairInt *vSubject;
  	vtPairInt *vXreader;
  	vtPairInt *vNickIp;
  	vtPairInt *vNickEmail;
  	vtPairInt *vNickEmailNg;
  	vtPairInt *vNewsHora;
  	vtPairInt *vSubjectNg;
	vtPairInt::iterator it;

	void define_quantity(void);
	void change_vigent(unsigned int header);
	void fill(void);
	void preenche();
	int  retornaXPostingsTotal(void);
	std::string percentage(int i);
	void put_together(vtPairInt *orig);
};

class NoFile {
	const std::string data;
public:
   NoFile(const char* const msg="NoFile found!"):data (msg) {}
   std::string get_message(void) { return data; }
};