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

// An image is represented by a binary matrix with 0 as a white pixel 
// and 1 as a black pixel. The black pixels are connected, 
// i.e., there is only one black region. 
// Pixels are connected horizontally and vertically. 
// Given the location (x, y) of one of the black pixels, 
// return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

// For example, given the following image:
// [
//   "0010",
//   "0110",
//   "0100"
// ]
// and x = 0, y = 2,

// Return 6.

#define vvc vector<vector<char>>

class Solution {
public:
  int minArea(vvc& image, int x, int y) {
  int left, right, up, down;
  left = right = y;
  up = down = x;
  fori (i, 0, sz(image)) {
    fori (j, 0, sz(image[0])) {
    if (image[i][j] == '1') {
      left = min(left, j);
      right = max(right, j);
      up = min(up, i);
      down = max(down, i);
    } 
    }
  }
  return (right - left + 1) * (down - up + 1);
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("p302-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
