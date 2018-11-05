#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  TrieNode *child[26];
  bool isLeaf;
  TrieNode() {
    isLeaf = false;
    for (int i = 0; i < 26; ++i)
      child[i] = nullptr;
  }
};

class WordDictionary {
private:
  TrieNode *root;
  bool find(string key, TrieNode *node) {
    for (int i = 0; i < key.size() && node; ++i) {
      if (key[i] != '.') 
        node = node->child[key[i] - 'a'];
      else {
        int k = 0;
        for (; k < 26; ++k)
          if (node->child[k] && find(key.substr(i+1), node->child[k])) 
            return true;
        // Note: none of all 26 buckets matched
        if (k == 26) return false; 
      }
    }
    return node && node->isLeaf;
  }

public:
  /** Initialize your data structure here. */
  WordDictionary() {
    root = new TrieNode();        
  }
  
  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); ++i) {
      int ch = word[i] - 'a';
      if (node->child[ch] == nullptr)
        node->child[ch] = new TrieNode();
      node = node->child[ch];
    }
    node->isLeaf = true;
  }
  
  /** Returns if the word is in the data structure. 
      A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return find(word, root); 
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
int main() {
  return 0;
}
