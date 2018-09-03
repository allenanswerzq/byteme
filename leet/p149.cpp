#include<bits/stdc++.h>
using namespace std;



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

// class Point {
// public:
//   int x;
//   int y;
//   Point() : x(0), y(0) {}
//   Point(int a, int b) : x(a), y(b) {}
//   bool operator < (Point aa) {
//     return x < aa.x; 
//   }
// };

class Solution {
public:
  int maxPoints(vector<Point>& points) {
  int n = sz(points);
  int res = 0;
  unordered_map<ll, int> mp;
  int cur, overlap, vertical;
  fori (i, 0, n) {
  cur = overlap = vertical = 0;
  fori (j, i + 1, n) {
  ll dy = points[j].y - points[i].y;
  ll dx = points[j].x - points[i].x;
  if (dx == 0 && dy == 0)
    ++overlap;
  else if (dx ==0)
    ++vertical;
  else {
    int g = __gcd(dx, dy);
    dx /= g;
    dy /= g;
    mp[(dy << 32) | dx]++;
    cur = max(cur, mp[(dy << 32) | dx]);
  }
  cur = max(cur, vertical);
  }
  mp.clear();
  res = max(res, cur + overlap + 1); 
  }       
  return res;
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p149-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
