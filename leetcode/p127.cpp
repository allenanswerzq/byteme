#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

#define vs vector<string>
#define vvs vector<vector<string>>
#define uss unordered_set<string>

class Solution {
public:
  // TODO
  void addNeighbors2(string inp, queue<string>& que, uss& wordSet) {
    for (int i = 0; i < inp.size(); ++i) 
      for (int k = 0; k < 26; ++k) {
        char old = inp[i];
        inp[i] = 'a' + k;
        if (wordSet.count(inp)) {
          que.push(inp);
          wordSet.erase(inp);
        }
        inp[i] = old;
      }
  }

  void addNeighbors(string word, queue<string>& que, uss& wordSet) {
    vector<string> del;
    for (auto dst : wordSet) {
      int cnt = 0;
      for (int i = 0; i < dst.size(); ++i) { 
        if (dst[i] != word[i]) ++cnt;
        if (cnt > 1) break;
      }
      if (cnt == 1) { 
        que.push(dst);
        del.push_back(dst);
      }
    }
    
    for (auto x : del)
      wordSet.erase(x);
  }

  // BFS
  int ladderLength(string beginWord, string endWord, vs& wordList) {
    queue<string> que; 
    uss wordSet(all(wordList));
    int level = 2;
    addNeighbors(beginWord, que, wordSet);   
    while (!que.empty()) {
      int n = que.size();
      for (int i = 0; i < n; ++i) {
        string word = que.front(); que.pop();
        if (word == endWord) return level;
        addNeighbors(word, que, wordSet); 
      }
      level++;
    }
    return 0;
  }
};

void test(string aa, string bb, vs cc) {
  Solution go;
  int ret = go.ladderLength(aa, bb, cc);
  output(1, ret); 
}

int main() {
  test("hit", "cog", {"hot","dot","dog","lot","log","cog"}); 
  test("hit", "cog", {"hot","dot","dog","lot","log"});
  return 0;
}
