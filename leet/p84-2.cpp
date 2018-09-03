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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Divide and conquer approach.
int build(vi& inp, vi& seg, int lo, int hi, int ix) {

  if (lo == hi) {
  seg[ix] = lo;
  // trace(ix, seg[ix]);
  return seg[ix];
  }

  int mid = lo + (hi - lo) / 2;
  int a = build(inp, seg, lo, mid, 2 * ix + 1);
  int b = build(inp, seg, mid + 1, hi, 2 * ix + 2);
  seg[ix] = inp[a] < inp[b] ? a : b;
  // trace(ix, seg[ix]);
  return seg[ix];
}

int rmq_util(vi& seg, int lo, int hi, int ss, int se, int ix) {
  // total overlap
  trace(lo, hi, ss, se);
  if (lo <= ss && se <= hi)
  return seg[ix];
  // no overlap
  else if (lo > se || hi < ss)
  return -1;
  // partial overlap
  int mid = ss + (se - ss) / 2;

  int a = rmq_util(seg, lo, hi, ss, mid, 2 * ix + 1);
  int b = rmq_util(seg, lo, hi, mid+1, se, 2 * ix + 2);
  //  
}

int rmq(vi& seg, int lo, int hi, int n) {
  return rmq_util(seg, lo, hi, 0, n-1, 0);
}

int go(vi& inp, vi& seg, int lo, int hi) {
  int n = sz(inp);
  if (lo > hi) return -(1<<31);
  if (lo == hi) return inp[lo]; 
  int mix = rmq(seg, lo, hi, n);
  return max(max(go(inp, seg, lo, mix-1), 
         go(inp, seg, mix+1, hi)),
         (inp[mix] * (hi - lo + 1)));
}

class Solution {
public:

  int largestRectangleArea(vi& aa) {
  int n = sz(aa);
  int x = (int)ceil(log2(n));
  int mlen = 2 * (int)pow(2, x) - 1;
  // trace(n, x, mlen);
  vi seg(mlen);
  build(aa, seg, 0, n - 1, 0);

  cout << rmq(seg, 0, 3, n) << endl; 
  // return go(aa, seg, 0, n-1);
  return 0;
  }
};

// Stack approach.
class Solution {
public:
  int largestRectangleArea(vector<int>& aa) {
  aa.pb(0);
  stack<int> stk;
  int res = 0;
  fori (i, 0, sz(aa)) {
    while(!stk.empty() && aa[i] <= aa[stk.top()]) {
    int h = aa[stk.top()]; stk.pop();
    int w = stk.empty() ? -1 : stk.top(); 

    res = max(res, h * (i - w - 1));
    cout << i << " " << w << " " << res << "\n";
    }
    // We still need to compute the area with `i`th bar as the smallest bar.
    // So push it into stack.
    stk.push(i);
  }
  return res;
  }
};

void TEST(vi aa) {
  Solution go;
  cout << go.largestRectangleArea(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  TEST({2,1,5,6,2,3});
  return 0;
}
