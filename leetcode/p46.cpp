#include<bits/stdc++.h>using namespace std;

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

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  void bt(vector<int>& aa, vector<int>& path, vector<vector<int>>& res) {
    int n = aa.size();
    if (path.size() == n) {
      res.push_back(path);
      return;
    } 

    for(int i = 0; i < n; ++i) {
      if (find(path.begin(), path.end(), aa[i]) != path.end()) 
        continue;
      path.push_back(aa[i]);
      bt(aa, path, res); 
      path.pop_back();
    }
  }

  vector<vector<int>> permute(vector<int>& aa) {
    vector<vector<int>> res;
    vector<int> path;
    bt(aa, path, res);
    return res;
  }

  // Permute num[begin ... end]
  // Invariant: num[0 ... begin-1] have been fixed/permuted
  void permuteRecursive(vector<int> &aa, int begin, vector<vector<int>>& ret) {
    if (begin >= aa.size()) {
      // One permutation instance
      ret.push_back(aa);
      return;
    }
    
    for (int i = begin; i < aa.size(); i++) {
      swap(aa[begin], aa[i]);
      permuteRecursive(aa, begin + 1, ret);
      swap(aa[begin], aa[i]);
    }
  }

  vector<vector<int>> permute1(vector<int> &aa) {
    vector<vector<int>> ret;
    permuteRecursive(aa, 0, ret);
    return ret;
  }
};

void test(vi aa) {
  Solution go;
  vvi ret = go.permute(aa); 
  fora (r, ret) {
    pvi(r);
  }
}    

int main() {
  test({1, 2, 3});
  return 0;
}
