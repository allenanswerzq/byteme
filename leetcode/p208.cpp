#include<bits/stdc++.h>
using namespace std;

class trieNode {
public:
  // If child[i] is not null means its child node contains char 'a'+i
  trieNode *child[26]; 
  // If current is a leaf node, following the path 
  // from root to leaf we can get a whole word.
  bool isLeaf;  
  trieNode() {
    isLeaf = false;
    for (int i = 0; i < 26; ++i)
      child[i] = nullptr;
  } 
};

class Trie {
private:
  trieNode *root;   
  trieNode *find(string key) {
    trieNode *node = root;
    for (int i = 0; i < key.size() && node; ++i)
      node = node->child[key[i] - 'a'];
    return node;
  }

public:
  /** Initialize your data structure here. */
  Trie() {
    root = new trieNode();
  }
  
  /** Inserts a word into the trie. */
  void insert(string ss) {
    trieNode *node = root;
    for (int i = 0; i < ss.size(); ++i) {
      int ch = ss[i] - 'a';
      if (node->child[ch] == nullptr)
        node->child[ch] = new trieNode();
      node = node->child[ch];
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

int main() {
  return 0;
}
