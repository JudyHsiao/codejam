#include "TextQuery.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

TextQuery::TextQuery(std::ifstream &is) :file (new vector<string>)
{
    std::string text;
    while(getline(is, text)){
        file->push_back(text);
        istringstream ss(text);
        string word;
        int n = file->size() -1;
        while(ss>>word) {
           
            auto &lines = wm[word];  //reference to pointer
            if (!lines){
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> no_data(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, no_data, file);
    else
        return QueryResult(sought, loc->second, file);
    
 }