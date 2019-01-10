#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;    
    
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isWord = false;
        ~TrieNode();
    };
    
    struct Trie {
        TrieNode* root;
        Trie():root(new TrieNode()){};
        void build(const vector<string>& words);
        void insert(const string& s);  
        ~Trie() {delete root; };
    };

    TrieNode::~TrieNode() {
        for (auto &p: children) {
            if (p.second !=nullptr)
                delete p.second;
        }
    }
    
    void Trie::build(const vector<string>& words) {
        for(const auto& s:words) {
            insert(s);
        }
    }

    void Trie::insert(const string& s) {
        TrieNode* curr = root;
        for (const auto ch: s) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isWord = true;
    }


    void dfs(const vector<vector<char>>& board, vector<vector<bool>>& used, int i, int j, TrieNode* t, string& s, vector<string>& ans ) {
        if (t->isWord) {
            ans.push_back(s);
        }
        const pair<int, int> dirs[4] = {{-1,0}, {0,1}, {1, 0}, {0,-1}};
        for(const auto &dir: dirs) {
            int x = i+ dir.first;
            int y = j + dir.second;
            if (x >= 0 && y >= 0 && x< board.size() & y< board[0].size()) {
                const char ch = board[x][y];
                if (used[x][y] == false && t->children.count(ch)) {
                    used[x][y] = true;
                    s.push_back(ch);
                    
                    dfs(board, used, x, y, t->children[ch], s, ans);
                    s.pop_back();
                    used[x][y] = false;   
                }
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        t.build(words);
        vector<string> ans;
        vector<vector<bool>> used (board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                char ch = board[i][j];
                if (t.root->children.count(ch)) {
                    string tmp (1,ch);
                    used[i][j] = true;
                    dfs(board, used, i, j, t.root->children[ch], tmp, ans);
                    used[i][j] = false;
                    
                }
            }  
        }
         
        return ans;
    }

    int main () {

        vector<vector<char>> board {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
        vector<string> words {"oath","pea","eat","rain"};
        vector<string> ans = findWords(board, words) ;
        for (const auto& s:ans) {
            cout << s << endl;
        }

        return 0;

    }