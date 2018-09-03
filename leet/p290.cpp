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

// class Solution {
// public:
//   bool wordPattern(string aa, string str) {
//     unordered_map<char, string> mp;
//     istringstream iss(str);
//     int i = 0;
//     for (string b; iss >> b; ++i) {
//       if (mp.count(aa[i])) {
//         if (mp[aa[i]] != b) return 0;
//       } else {
//         fora (it, mp)
//           if (it.second == b) return 0;
//         mp[aa[i]] = b;
//       }
//     }      
//     return i == sz(aa);
//   }
// };

// #define sz(x) (int)(x).size()
class Solution {
public:
  bool wordPattern(string aa, string str) {
  unordered_map<char, int> mp1;
  unordered_map<string, int> mp2;
  istringstream iss(str);
  int i = 0;
  for (string b; iss >> b; ++i) {
  if (mp1.count(aa[i]) || mp2.count(b)) {
  // trace(aa[i], b);
  if (mp1[aa[i]] != mp2[b]) 
    return 0;
  } else {
  // trace(i, aa[i], b);
  mp1[aa[i]] = mp2[b] = i + 1;
  }
  }      
  return i == sz(aa);
  }
};

// #define LOCAL_FILE

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("p290-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  Solution go;
  int r = go.wordPattern("abba", "dot cat cat fish");
  output(1, r);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
