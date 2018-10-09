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

class Node {
public:
  string word;
  int level;
  Node* pre;
  Node (string w, int l, Node* p) 
    : word(w), level(l), pre(p) {}
};

class Solution {
public:
  vvs findLadders(string start, string end, vs& wordList) {
    vvs res;
    unordered_set<string> wordSet(all(wordList));
    if (!wordSet.count(end)) return res;
    if (wordSet.count(start)) wordSet.erase(start);

    int level = 1;
    bool ok = 0;
    queue<Node*> que; 
    que.push(new Node(start, level, nullptr));

    while (!que.empty()) {
      int n = que.size();
      set<string> del;
      for (int i = 0; i < n; ++i) {
        auto node = que.front(); que.pop();
        trace(node->word, node->level);
        if (node->word == end) {
          ok = 1;
          Node* cur = node;
          vs path;
          while (cur != nullptr) {
            path.insert(path.begin(), cur->word);
            cur = cur->pre;
          }
          res.push_back(path);
        } else {
          fora (w, wordSet) {
            int k = 0;
            fori (i, 0, sz(w)) {
              if (w[i] != node->word[i]) ++k;
              if (k > 1) break;
            } 
            if (k == 1) {
              que.push(new Node(w, level+1, node));
              del.insert(w);
            }
          }  
        } 
      }

      fora (x, del) {
        wordSet.erase(x);
      }

      ++level;
      if (ok) break;
    }
    return res;
  }
};

void test(string aa, string bb, vs cc) {
  Solution go;
  vvs ret = go.findLadders(aa, bb, cc);
  fora (r, ret) {
    pvi(r);
  }
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
  test("a", "c", {"a", "b", "c"});
  test("red", "tax", {"ted","tex","red","tax","tad","den","rex","pee"});

  return 0;
}
