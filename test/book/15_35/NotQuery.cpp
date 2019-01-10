#include "NotQuery.h"
#include <memory>  // make_shared
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;
inline Query operator~(const Query &q) {
    return std::shared_ptr<Query_base>(new NotQuery(q));
}

QueryResult NotQuery::eval(const TextQuery& text) const 
{
    auto result = q.eval(text);
    auto ret_line = make_shared<set<line_no>>();

    auto sz = result.get_file()->size();
    auto beg = result.begin(), end = result.end();
    for( size_t n = 0; n!=sz; ++n) {
        if (beg == end || *beg != n) 
            ret_line->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_line, result.get_file());

}