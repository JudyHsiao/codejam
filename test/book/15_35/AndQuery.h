#ifndef AND_QUERY_H
#define AND_QUERY_H

class TextQuery;
class QueryResult;

#include <string>
#include "BinaryQuery.h"

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &l, const Query &r):BinaryQuery(l,r, "&"){};
    QueryResult eval(const TextQuery& t) const ;
};

Query operator&(const Query &, const Query &);
#endif
