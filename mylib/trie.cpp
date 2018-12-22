#include <vector>
#include <iostream> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 

    TrieNode() {
        isEndOfWord =false;
        for (int i = 0; i < ALPHABET_SIZE; i++) 
            children[i] = NULL; 
    }; 
} ; 
  
void deleteTrie(struct TrieNode *root) {
    for(auto c: root->children) {
        if (c!=NULL) {
            deleteTrie(c);
        }
    }
    delete(root);
}

void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *cur = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!cur->children[index]) 
            cur->children[index] = new TrieNode();
  
        cur = cur->children[index]; 
    } 
  
    // mark last node as leaf 
    cur->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = new TrieNode();
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 



    // Delete Trie
    deleteTrie(root);
    cout << "Finish\n" << endl;

    return 0; 
} 