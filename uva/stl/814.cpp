#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;



void split(const string& s, char delim, vector<string>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(token);
    }
    return;
}

struct User{
    string name;
    string mta;
};

bool cmp (const User& a,const User& b) {
    return a.mta < b.mta;
}

void parse_address(const string& s, User& u){
    auto k = s.find('@');
    u.name = s.substr(0,k);
    u.mta = s.substr(k+1);
} 

int main(){
    string s;
    int k;
    string t;
    map<string,set<string>> mta;
    while(cin >> s && s != "*") {
        cin >> s >> k;
        while(k--) { 
            cin >> t; 
            mta[s].insert(t); 
        }
    }

    while(cin >> s && s != "*") {
        //sender and receiver
        User sender;
        parse_address(s, sender);

        vector<string> r_mta; // 所有需要连接的mta，按照输入顺序
        map<string, set<string>> receiver;
        map<string, vector<string>> dest;
        while(cin >> t && t != "*") {
            User r ;
            parse_address(t, r);
            if (!receiver.count(r.mta)){
                r_mta.push_back(r.mta);
            }
            if (!receiver[r.mta].count(r.name)){
                receiver[r.mta].insert(r.name);
                dest[r.mta].push_back(r.name);
            }
        }

        getline(cin, t); 

        string data;
        while(getline(cin, t) && t[0] != '*') data += "     " + t + "\n";

        for(auto it:r_mta) {
            vector<string> r_names = dest[it];
            cout << "Connection between "<< sender.mta <<" and "<< it <<"\n";
            cout << "     HELO "<<sender.mta<<"\n";
            cout << "     250\n";
            cout << "     MAIL FROM:<" << sender.name << "@" << sender.mta <<">\n";
            cout << "     250\n";
            bool send = false;
            for (auto name: r_names) {
                cout << "     RCPT TO:<" << name<<"@"<< it << ">\n";
                if(mta[it].count(name)) {
                    cout << "     250\n";
                    send = true;
                } else{
                    cout << "     550\n";
                }
            }

            if(send) {
                cout << "     DATA\n";
                cout << "     354\n";
                cout << data;
                cout << "     .\n";
                cout << "     250\n";
            }
            cout << "     QUIT\n";
            cout << "     221\n";
        }
    }
    return 0;
}