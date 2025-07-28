#ifndef _CLIENTNNTP_H
#define _CLIENTNNTP_H

#include "PairInt.h"
#include "NNTPSocket.h"

#include <fstream>
#include <vector>
#include "date/sdate.h"

typedef std::vector<std::string> vtStr;

class CClientNNTP
{
    CNNTPSocket *nntp;
    int totalMsgs;
    std::ofstream outFile;
    std::string data_vigente;
    std::string data_posterior;
    std::string data_file;
    vtStr  msgsIDs;
//	void defineNewsQnt(MainFrame *pMain);
    vtStr retornaIds(void);

  public:
    int QntMsgBaixadasPorPacote;
    int newsTotal;
    std::string tempoDeDownload;
    CClientNNTP() {};
    CClientNNTP(sdate _date, std::string server);
    virtual ~CClientNNTP() {;};
    void gravar(vtStr &headers);
    void run(void);
};

#endif
 // _CLIENTNNTP_H
