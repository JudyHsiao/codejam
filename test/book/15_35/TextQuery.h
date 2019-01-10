#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include "QueryResult.h"

class TextQuery {

public:
    using line_no = std::vector<std::string>::size_type;
    explicit TextQuery (std::ifstream&);
    QueryResult query(const std::string&) const;

    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

};

#endif