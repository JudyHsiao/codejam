#include "Query.h"
#include "WordQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "AndQuery.h"
#include "OrQuery.h"


Query::Query(const std::string & s):q(new WordQuery(s)) {
  std::cout << "Query::Query(const std::string &)" << std::endl;
}

QueryResult Query::eval(const TextQuery& t) const {
    return q->eval(t);
}

std::string Query::rep() const { 
    return  q->rep();
}

std::ostream& operator << (std::ostream&os , const Query& query) {
    os << query.rep();
    return os;
}


