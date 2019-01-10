#include "AndQuery.h"
#include <memory>  // make_shared
#include <algorithm>  // set_intersection
#include <iterator>  // inserter
#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>

using namespace std;

Query operator&(const Query &lhs, const Query &rhs) {

  std::cout << "Query operator&(const Query &, const Query &)" << std::endl;

  // NOTE we cannot use `std::make_shared` here, because the type of the
  // dynamically created object and the type of the object pointed by shared
  // pointer are different.
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


QueryResult AndQuery::eval(const TextQuery& text) const 
{
    auto left = lhs.eval(text);
    auto right = rhs.eval(text);

    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, (*ret_lines).begin()));



    return QueryResult(rep(), ret_lines, left.get_file());

}
