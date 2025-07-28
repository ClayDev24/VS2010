#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <iterator>
#include "pair.h"
#include "clayutils.h"
    
//typedef pair<int, string> pss;
    
/*class cmp_header
{
public:
    //sortby(HEADER CPair::*m_key) : m_key(m_key) {}    
    bool operator()(const CPair &p1, const CPair &p2) const
    {
        return p1.get_key() < p2.get_key();
    }
    //private:
    //    HEADER CPair::m_key;
};*/
    
//ostream &operator<<(ostream &out, CPair const &p)
//{
//    return out << "    " << clb::int2str(p.get_key()) << " " << *p.get_value() << endl;
//}

bool compare_myObjects(const CPair &a, const CPair &b) {
    return a.get_key() < b.get_key();
}
    
int main()
{
    vector<CPair> namecity;

    string *a = new string("Godalming");    
    namecity.push_back(CPair(ID_HEADER_IP, a));// new string("Godalming")));
    namecity.push_back(CPair(ID_HEADER_NICKNAME,    new string( "Eugene")));
    namecity.push_back(CPair(ID_HEADER_SUBJECT,  new string("Eugene")));
    namecity.push_back(CPair(ID_HEADER_GROUPS,    new string( "Godalming")));
    namecity.push_back(CPair(ID_HEADER_EMAIL,  new string("Chicago")));
    namecity.push_back(CPair(ID_HEADER_HOUR,   new string("Eugene")));
    
//    stable_sort(namecity.begin(), namecity.end(), compare_myObjects);//sortby(&pss::first));
    
    cout << "sorted by names:\n";
//    copy(namecity.begin(), namecity.end(), ostream_iterator<CPair>(cout));        
    vector<CPair>::iterator it;
    for(it = namecity.begin(); it != namecity.end(); it++) {      
        cout << clb::int2str((*it).get_key()) << " - " << *(*it).get_value() << endl;
    }
                                                                    
//    stable_sort(namecity.begin(), namecity.end(), sortby(&pss::first));    
//    cout << "sorted by names within sorted cities:\n";
//    copy(namecity.begin(), namecity.end(), ostream_iterator<pss>(cout));
}
