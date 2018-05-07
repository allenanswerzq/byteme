#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

class TrieNode {
public:
  TrieNode *child[26];
  bool isLeaf;
  TrieNode() {
    isLeaf = false;
    for (int i=0; i<26; ++i)
      child[i] = nullptr;
  }
};

// accepted
class WordDictionary {
private:
  TrieNode *root;
  bool find(string key, TrieNode *node) {
    for (int i=0; i<key.size() && node; ++i) {
      if (key[i] != '.')
        node = node->child[key[i]-'a'];
      else {
        int k = 0;
        for (; k<26; ++k)
          if (node->child[k] && find(key.substr(i+1), node->child[k])) return true;
        if (k == 26) return false; // Note: none of all 26 buckets matched
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
      for (int i=0; i<word.size(); ++i) {
        if (node->child[word[i]-'a'] == nullptr)
          node->child[word[i]-'a'] = new TrieNode();
        node = node->child[word[i]-'a'];
      }
      node->isLeaf = true; // current node is a leaf node 
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
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
int main(int argc, char** argv) {
    return 0;
}
