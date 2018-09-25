#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;
struct record{
    string num;
    string file;
    mutable int count;
    record(string n,string f):num(n),file(f),count(1){}
    //指定符合hash函数的operator==重载
    bool operator == (const record& rhs) const{
    {
        
        return (rhs.num==num)&&(rhs.file==file);
    }
};


//指定hasher 将作为模板第二个参数
struct record_hash{
    size_t operator()(const struct record& _r) const {
    string tmp=_r.file+_r.num;
    return std::hash<string>()(tmp);
    }
};

int main()
{
    unordered_set<record,record_hash> records;
    records.insert(record("zhang","xiao"));
    record r("zhang","xiao");
    auto it = records.find(r);
    cout<<it->num<<" "<<it->file<<endl;
    return 0;
}