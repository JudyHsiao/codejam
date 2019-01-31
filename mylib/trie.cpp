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



  
// Driver 
int main() 
{ 

    vector<string> words = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
  
    Trie t;
  
    t.build(words);
  
    const vector<int>& v = t.startwith("");
    for(const auto& i: v) {
        cout << words[i] << endl;
    }
    cout << "Finish" << endl;

    return 0; 
} 