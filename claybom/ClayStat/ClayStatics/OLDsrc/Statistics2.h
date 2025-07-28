#ifndef _STATISTICS_H
#define _STATISTICS_H

#include <cstdio>
#include <vector>
#include "PairInt.h"
#include "Article.h"
#include "ClayUtils.h"

typedef std::vector<std::string> vtStr;
typedef std::vector<CArticle*>   vtMsg;
typedef std::vector<CPairInt*>   vtPairInt;

//namespace clb {

class CStatistics
{
public:
    CStatistics();
    ~CStatistics();
    int m_totalPseudo;
    int m_totalPseudoMaisEmail;
    int m_totalNews;
    int m_totalMsgs;
    int m_totalXreader;
    int m_totalNovos;
    int m_totalCrossMsgs;
    int m_totalGroups;
    int m_totalCrossGroups;
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
    std::string show(HEADER header, std::string kind);
    std::string retorna_ngs_geral(void);
    std::string pesquisa_pseudo(const std::string &nick);
    std::string advanced_search(const std::string &nick, const HEADER &header);
    vtPairInt* retorna_ngs_inscritos(const std::string &nick, const HEADER &hdr);
    std::string postagem(const std::string &s);  	  	
    vtStr top_happen_key(int qts, HEADER header);
    std::string  top_happen(int qts, HEADER header);
    std::string  pico(void);
    void readFile(std::string file_name, std::string period);
    void define_partial(void);	
    std::string modelo1(const int &quantity);

private:
    vtMsg   *vArticlesGeral;
    vtMsg   *vArticlesPartial;
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
    vtPairInt *vSubjectEng;

    
    void change_vigent(HEADER header);
    void fill(void);
    void preenche();
    void define_quantity(void);
    int retornaXPostingsTotal(void);
    std::string percentage(int i);
    void put_together(vtPairInt *orig);
};

class NoFile {
	const std::string data;
public:
   NoFile(const char* const msg = 0) : data (msg) {}
   std::string get_message(void) { return data; }
};


#endif // _STATISTICS_H

