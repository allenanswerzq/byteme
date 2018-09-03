#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Note: here a reference symbol can make big difference.
// I guess it doesn't need to allocate a set on stack
// every time, so the speed will be improved.
bool check(string s, set<str>& st) {
// bool check(string s, set<str> st) {
  int n, m;
  n = sz(s);
  if (n == 0) return 0;
  // dp[i] equals true if s[0...i-1] can be broke.
  int dp[n + 1];
  mst(dp, 0);
  fori (i, 1, n + 1) {
  if (dp[i] == 0) {
  str tmp = s.substr(0, i);
  if (st.count(tmp)) dp[i] = 1;
  }
  if (dp[i] == 1) {
  // s[0...i] can be broke, now we need to check the
  // rest part of the string.
  fori (j, i + 1, n + 1) {
  if (st.count(s.substr(i, j - i)))
    dp[j] = 1;  
  }
  }
  if (dp[n]) return 1;
  }
  return 0;
}

vector<string> findAllConcatenatedWordsInADictDP(vector<string>& words) {
  vs res;
  set<str> st;
  sort(all(words), [&](str a, str b){
  return sz(a) < sz(b);
  });
  fori (i, 0, sz(words)) {
  str cur = words[i];
  if (check(cur, st)) 
  res.pb(cur);
  st.insert(cur); 
  }
  return res;
}

// TODO: still has problems with this trie solution.
// Already wasted a lot time...
class TrieNode {
public:
  bool leaf;
  TrieNode* child[26];
  TrieNode() {
  leaf = 0;
  fori (i, 0, 26)
  child[i] = null;
  }
};

void dfs(TrieNode* root) {
  TrieNode* cur = root;
  fori (i, 0, 26) {
  if (cur->child[i]) {
  char t = i + 'a';
  cout << t;
  if (cur->child[i]->leaf)
  cout << "|";
  dfs(cur->child[i]);
  }
  }
}

bool check(TrieNode* root, string w, int ix, int count) {
  TrieNode* cur = root;
  int n = sz(w);
  cout << w << " " << ix << " " << count << "\n";
  fori (i, ix, n) {
  char c = w[i];
  if (cur->child[c-'a'] == null) return 0;
  if (cur->child[c-'a']->leaf) {
  if (ix == n - 1) return count >= 1;
  if (check(root, w, i + 1, count + 1)) {
  return 1;
  }
  }
  cur = cur->child[c - 'a'];
  }
  return 0;
}

void insert(TrieNode* root, str inp) {
  TrieNode *cur = root;
  fora (c, inp) {
  if (cur->child[c-'a'] == null) 
  cur->child[c-'a'] = new TrieNode();
  cur = cur->child[c-'a'];
  } 
  cur->leaf = 1;
}

vs findAllConcatenatedWordsInADictTrie(vs& words) {
  vs res;
  int n = sz(words);
  if (n <= 0) return res;
  TrieNode *root = new TrieNode();
  fora (w, words) {
  if (sz(w))
  insert(root, w);
  }

  dfs(root);
  cout << endl;

  fora (w, words) {
  if (sz(w) && check(root, w, 0, 0))
  res.pb(w);
  }
  return res;
}

class Solution {
public:
  vs findAllConcatenatedWordsInADict(vs& words) {
  // return findAllConcatenatedWordsInADictDP(words); 
  return findAllConcatenatedWordsInADictTrie(words);
  }
};

void test(vs aa) {
  Solution go;
  vs res = go.findAllConcatenatedWordsInADict(aa);
  fora (r, res)
  cerr(r);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  // test({"a", "ab"});
  test({"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"});

  return 0;
}
