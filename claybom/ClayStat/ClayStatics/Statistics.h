#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include <string>
#include <cctype> // isspace
#include <ctime>

#include "PairInt.h"
#include "Article.h"

//#define operador LessThan
#define NAME 0
#define QUANTITY 1

typedef std::vector<std::string> vtStr;
typedef std::vector<CArticle*>   vtMsg;
typedef std::vector<CPairInt*>   vtPairInt;
typedef std::vector<CPair*>      vtPair;


class CStatistics
{
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
    HEADER m_mode;

    bool is_empty(void);
    std::string show(HEADER header, int kind);
    std::string retorna_ngs_geral(void);
    std::string pesquisa_pseudo(const std::string &nick);
    std::string advanced_search(const std::string &nick, HEADER header);
    vtPairInt*  retorna_ngs_inscritos(const std::string &nick, const int &hdr);
    std::string postagem(const std::string &s);
    vtStr       top_happen_key(int qts, HEADER header);
    std::string top_happen(int qts, HEADER header);
    std::string pico(void);
    void readFile(std::string file_name, std::string period);
    void define_partial(void);
    std::string modelo1(const int &quantity);
    void change_vigent(HEADER header);

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
    void fill(void);
    void preenche();
    int  retornaXPostingsTotal(void);
    std::string percentage(int i);
    void put_together(vtPairInt *orig);
};

class NoFile {
    const std::string data;
public:
   NoFile(const char* const msg = "NoFile found!") : data (msg) {}
   std::string get_message(void) { return data; }
};
