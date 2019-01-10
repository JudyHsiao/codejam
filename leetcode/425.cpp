#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    vector<int> words;
    bool isWord = false;
    ~TrieNode();
};

struct Trie {
    TrieNode* root; 
    Trie(): root(new TrieNode()){};
    void build(const vector<string>& words);
    void insert(const string& s, int id);
    const vector<int>& startwith(const string& s) const; 
    static vector<int> empty;
    ~Trie();  
};

vector<int> Trie::empty;

 TrieNode::~TrieNode() {
     cout << "~TrieNode()" << endl;
     for(auto& p: children) {
        if (p.second != nullptr)
            delete p.second;
     }
 }

 Trie::~Trie() {
    cout << "~Trie()" << endl;
    delete root;
 }

void Trie::build(const vector<string>& words) {
 
     for (int i =0; i < words.size(); i++){
        insert(words[i], i);
     }
}
void Trie::insert(const string& s, int id) {
 
    TrieNode* cur = root;
    for (const auto ch:s){
        if (cur->children[ch] == nullptr) {
            cur->children[ch] = new TrieNode();
        }
        cur->words.push_back(id);
        cur = cur->children[ch];
    }
    cur->words.push_back(id);
    cur->isWord=true;
}

const vector<int>&  Trie::startwith(const string& s) const{
    TrieNode* cur = root;
    for (const auto ch:s){
        if (cur->children[ch] == nullptr) {
            return empty;
        }
        cur = cur->children[ch];
    }
    return cur->words;
}







void dfs (const Trie& t, int n , const vector<string>& words, vector<int>& curr, vector<vector<string>>& ans) {
    
    int k = curr.size();
    if (k == n) {
        vector<string> tmp;
        for (const auto &i:curr)
            tmp.push_back(words[i]);
        ans.push_back(tmp);
    }
    string prefix;
    for(const auto& i:curr) {
        prefix.push_back(words[i][k]);
    }

    const vector<int>& v = t.startwith(prefix);
    for (const auto &i: v) {
        curr.push_back(i);
        dfs(t, n, words, curr, ans);
        curr.pop_back();
    }

    return;    
}
    
vector<vector<string>> wordSquares(const vector<string>& words) {
    if (words.size() == 0)
        return vector<vector<string>>{};
    
    Trie t ;
    t.build(words);
    vector<vector<string>> ans;
    vector<int> curr;
    dfs(t, words[0].size(), words, curr, ans);
    return ans;
}

int main() {
    
   vector<vector<string>> ans = wordSquares({"abat","baba","atan","atal"});
   for (const auto&v: ans) {
    for (const auto &s :v)
        cout << s << endl;
    cout << endl;
   }
   return 0;
}