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

class Solution {
public:
  vvs groupAnagrams1(vector<string>& aa) {
    unordered_map<string, vs> mp;
    string tmp;
    for (auto& a : aa) {
      string tmp = a;
      sort(all(tmp));
      mp[tmp].push_back(a);
    } 

    vvs ret;
    for (auto& it : mp) {
      ret.push_back(it.second);
    }
    return ret;
  }

  vvs groupAnagrams(vs& aa) {
    vvs ret;
    unordered_map<string, int> mp;
    int cnt = 0;
    string tmp;
    fora (a, aa) {
      tmp = a;
      sort(all(tmp));
      if (mp.count(tmp)) {
        ret[mp[tmp]].push_back(a);
      } else {
        mp[tmp] = cnt++;
        ret.push_back({a});
      }
    }
    return ret;
  }
};

int main() {
  return 0;
}
