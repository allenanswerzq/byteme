#include<bits/stdc++.h>
using namespace std;

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

// #define LOCAL_FILE

#define vi vector<int>
#define vpii vector<pair<int, int>>

class Solution {
public:
  vi findMinHeightTrees(int n, vpii& edges) {
    if (n == 1) return {0};
    vi res;
    deque<int> dq;
    vector<unordered_set<int>> gg(n);
    fora (e, edges) {
      gg[e.first].insert(e.second);
      gg[e.second].insert(e.first);
    }

    // Push all leaves into queue.
    fori (i, 0, n) {
      if (gg[i].size() == 1)
      dq.push_back(i);
    }

    while (n > 2) {
      int k = sz(dq);
      n -= k;
      fori (i, 0, k) {
        int t = dq.front(); dq.pop_front();
        // trace(n, t);
        fora (e, gg[t]) {
          gg[e].erase(t);
          if (gg[e].size() == 1) dq.push_back(e);
        }
      }
    }

    while (sz(dq)) {
      res.push_back(dq.front());
      dq.pop_front();
    }

    return res;
  }
};

void test(int n, vpii edges) {
  Solution go;
  vi res = go.findMinHeightTrees(n, edges);
  pvi(res);
}

int main() {

  test(4, {{1, 0}, {1, 2}, {1, 3}});
  test(6, {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}});

  return 0;
}
