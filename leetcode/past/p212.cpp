#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define vvc vector<vector<char>> 
#define vvi vector<vector<int>>

class trieNode {
public:
  trieNode *child[26]; 
  bool isLeaf;  
  trieNode() {
    isLeaf = false;
    for (int i=0; i<26; ++i)
      child[i] = nullptr;
  } 
};

// Use Trie Accepted 
class Trie {
private:
  // root node of the trie
  trieNode *root;   
  trieNode *find(string key) {
    trieNode *node = root;
    for (int i = 0; i< key.size() && node; ++i)
      node = node->child[key[i] - 'a'];
    return node;
  }

public:
  /** Initialize your data structure here. */
  Trie() {
    root = new trieNode();
  }
  
  /** Inserts a word into the trie. */
  void insert(string key) {
    trieNode *node = root;
    for (int i = 0; i < key.size(); ++i) {
      int ch = key[i] - 'a';
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


Trie root;
unordered_set<string> st;
class Solution {
public:
  void bt(vvc& board, int x, int y, string path, vvi& visit, int max_width)  {
    if (path.size() > max_width) return;
    if (!root.startsWith(path)) return;

    if (root.search(path)) {
      st.insert(path);
    }

    vvi dirs = {{0,1},{0,-1},{1, 0}, {-1, 0}};
    visit[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];
      if (0<=nx && nx<board.size() && 0<=ny && ny<board[0].size() && 
          visit[nx][ny]==0) {
        path += board[nx][ny];
        bt(board, nx, ny, path, visit, max_width);
        path.pop_back();
      }
    } 
    visit[x][y] = 0;
  }

  vector<string> findWords(vvc& board, vs& words) {
    if (words.size() <= 0) return {};
    root = Trie();
    int max_width = 0;
    for (auto& w : words) {
      root.insert(w);
      max_width = max((int)w.size(), max_width);
    } 

    string path = "";
    vvi visit(board.size(), vi(board[0].size(), 0));
    for (int i = 0; i < board.size(); ++i) 
      for (int j = 0; j < board[0].size(); ++j) {
        bt(board, i, j, path + board[i][j], visit, max_width);
      }

    vector<string> ret;
    for (auto& m : st)
      ret.push_back(m);

    return ret;
  }
};

int main() {
  return 0;
}
