#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// accepted
class trieNode {
public: // Note: all below variables must bu public
  // if child[i] not null means its child node contains char 'a'+i
  trieNode *child[26]; 
  // if current is a leaf node, following the path from root to leaf we can get whole word
  bool isLeaf;  
  trieNode() {
    isLeaf = false;
    for (int i=0; i<26; ++i)
      child[i] = nullptr;
  } 
};

class Trie {
private:
  trieNode *root;   // root node of the trie
  // NOte: more tricky part
  trieNode *find(string key) {
    trieNode *node = root;
    for (int i=0; i<key.size() && node; ++i)
      node = node->child[key[i] - 'a'];
    return node;
  }

public:
    /** Initialize your data structure here. */
    Trie() {
      root = new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
      trieNode *node = root;
      for (int i=0; i<s.size(); ++i) {
        if (node->child[s[i] - 'a'] == nullptr)
          node->child[s[i] - 'a'] = new trieNode();
        node = node->child[s[i] - 'a'];
      }
      node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      trieNode *p = find(word);
      return p && p->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       trieNode *p = find(prefix); 
       return p != nullptr;
    }
};

int main(int argc, char** argv) {
    return 0;
}
