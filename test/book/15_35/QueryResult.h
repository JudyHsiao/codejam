#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <vector>
#include <set>
#include <string>

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
                sought(s),file(f),lines(p){};
    std::set<line_no>::iterator begin();
    std::set<line_no>::iterator end();
    std::shared_ptr<std::vector<std::string>> get_file();

private:
    std::string sought;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<line_no>> lines;
};
#endif