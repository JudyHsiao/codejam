#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>



using namespace std;
typedef set<int> Set;

map<Set,int> IDcache; // 把集合映射成ID
vector<Set> Setcache; // 根据ID取集合

int ID(Set x) {
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x); // 添加新集合
    return IDcache[x] = Setcache.size() - 1;
}

void dup(stack<int>& S) {
    S.push(S.top());
}

void push(stack<int>& S) {
    S.push(ID(Set()));
}

void print(stack<int> S) {
    cout << "size: "<< S.size() << "\n" ;
    while (!S.empty()) {
         cout << S.top();
         S.pop();
    }
    printf("\n");
}

void my_intersect(stack<int>& S){
    int a = S.top();
    S.pop();
    int b = S.top();
    S.pop();

    Set sa = Setcache[a];
    Set sb = Setcache[b];

    Set x;
    set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(x,x.begin()));
    S.push(ID(x));

}

void add(stack<int>& S){
    int a = S.top();
    S.pop();
    int b = S.top();
    S.pop();

    Set sa = Setcache[a];
    Set sb = Setcache[b];

    Set x = sb;
    x.insert(ID(sa));
    S.push(ID(x));

}

void my_union(stack<int>& S) {
    int a = S.top();
    S.pop();
    int b = S.top();
    S.pop();

    Set sa = Setcache[a];
    Set sb = Setcache[b];

    Set x;
    set_union(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(x,x.begin()));
    S.push(ID(x));
}

int main() {
    int T, N;
    string op;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        stack<int> S;

        for (int i = 0; i< N; i++){
            cin >> op;
            if (op == "PUSH")
                push(S);        
            else if (op == "DUP")
                dup(S);
            else if (op == "UNION")
                my_union(S);
            else if (op =="INTERSECT")
                my_intersect(S);
            else if (op == "ADD")
                add(S);
            cout << Setcache[S.top()].size() << endl;
        }
        cout << "***" << endl;
    }
}