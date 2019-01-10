#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int count = count_if(v.begin(), v.end(), bind(greater<int>(),  _1, 1024));
    cout << count << endl;

    std::vector<std::string> vs { "pooh", "pooh", "abc", "pooh" };

    const auto &it = std::find_if(vs.begin(), vs.end(),
      bind(not_equal_to<string>(), _1, "pooh"));

    cout << *it << endl;

    transform(v.begin(), v.end(), v.begin(),
      bind(multiplies<int>(), _1, 2));

    for (const auto & n :v)
        cout << n << endl;

    return 0;

}