#ifndef NOT_QUERY_H
#define NOT_QUERY_H

class TextQuery;
class QueryResult;

#include <string>
#include <memory>
#include <iostream>
#include "Query.h"
#include "Query_base.h"

class NotQuery:public Query_base {
    friend Query operator~(const Query &);
    NotQuery (const Query &query):q(query){
        std::cout << "NotQuery::NotQuery(const Query &)" << std::endl;
    };
    QueryResult eval(const TextQuery& t) const override;
    std::string rep() const override {return "~(" + q.rep()+ ")";};
    Query q;
};

Query operator~(const Query &);
#endif
