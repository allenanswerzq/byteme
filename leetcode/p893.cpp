#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl;
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Disjoint {

private:
  vector<int> p, rank, setSizes;
  int numSets;

public:
  Disjoint(int N) {
    numSets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
    setSizes.assign(N, 1);
  }
  
  int findSet(int i) {
    return (p[i] == i) ? i : p[i] = findSet(p[i]);
  }

  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        setSizes[findSet(x)] += setSizes[findSet(y)];
        p[y] = x;
      } else {
        setSizes[findSet(y)] += setSizes[findSet(x)];
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
      numSets--;
    }
  }

  int setSize(int i) {
    return setSizes[findSet(i)];
  }

  int numDisjointSets() {
    return numSets;
  }
};

bool check(string aa, string bb) {
  if (aa == bb) return 1;
  vi dp0(256, 0);
  vi dp1(256, 0);
  for (int i = 0; i < sz(aa); i += 2) {
    dp0[aa[i]]++;  
    dp0[bb[i]]--;
  }
  for (int i = 1; i < sz(aa); i += 2) {
    dp1[aa[i]]++;
    dp1[bb[i]]--;
  }

  fori (i, 0, 256) {
    if (dp0[i] || dp1[i]) return 0;
  }

  return 1;
}

class Solution {
public:
  int numSpecialEquivGroups(vector<string>& aa) {
    int n = sz(aa);
    Disjoint djs(n);    
    fori (i, 0, n) {
      fori (j, i + 1, n) {
        if (check(aa[i], aa[j])) 
          djs.unionSet(i, j);  
      }
    } 
    return djs.numDisjointSets();
  }
};

void test(vs aa) {
  Solution go;
  int r = go.numSpecialEquivGroups(aa);
  output(r);
}

int main() {
  test({"a","b","c","a","c","c"}); 
  test({"aa","bb","ab","ba"});
  test({"abc","acb","bac","bca","cab","cba"});
  test({"abcd","cdab","adcb","cbad"});
  return 0;
}
