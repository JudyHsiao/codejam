#include "QueryResult.h"
#include <algorithm>
#include <iostream>
using namespace std;

std::ostream& print(std::ostream& os,  const QueryResult& r) {
    os  << r.sought << " occurs " << r.lines->size() << " " << endl;
    for (const auto &no: *(r.lines)){
        os << "\tline: " << no << endl;
    } 
    return os;
}

std::set<QueryResult::line_no>::iterator QueryResult::begin(){
    return lines->begin();
}
std::set<QueryResult::line_no>::iterator QueryResult::end(){
    return lines->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file() {
    return file;
}
