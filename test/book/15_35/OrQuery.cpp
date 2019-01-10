#include "OrQuery.h"
#include <memory>  // make_shared
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

Query operator|(const Query &lhs, const Query &rhs) {

  std::cout << "Query operator|(const Query &, const Query &)" << std::endl;
  // NOTE we cannot use `std::make_shared` here, because the type of the
  // dynamically created object and the type of the object pointed by shared
  // pointer are different.
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


QueryResult OrQuery::eval(const TextQuery& text) const 
{
    auto left = lhs.eval(text);
    auto right = rhs.eval(text);

    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());

}