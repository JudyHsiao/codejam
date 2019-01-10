#ifndef WORD_QUERY_H
#define WORD_QUERY_H

#include "TextQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"


class WordQuery: public Query_base {
    friend class Query;
    WordQuery (const std::string &s):query_word(s){};
    QueryResult eval(const TextQuery& t) const {return t.query(query_word);};
    std::string rep() const {return query_word;};
    std::string query_word;
};


#endif
