#ifndef OR_QUERY_H
#define OR_QUERY_H

#include "BinaryQuery.h"

class OrQuery:public BinaryQuery{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &l, const Query &r):BinaryQuery(l,r, "|"){};
    QueryResult eval(const TextQuery& t) const ;
};

Query operator|(const Query &, const Query &);
#endif
