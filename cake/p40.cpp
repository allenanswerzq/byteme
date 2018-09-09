#include<bits/stdc++.h>
using namespace std;


// This approach destorys our input.
int findDuplicate(vi& v) {
  if (v.empty()) return -1;
  sort(all(v));
  int n = sz(v);
  int lo=0, hi=1;
  while (hi < n) {
    int p = 1;
    while (hi<n && v[hi] == v[lo]) {
      hi++;
      p++;
    }
    if (p > 1) 
      return v[lo];
    lo = hi;
    ++hi;
  }
  return -1;
}

unsigned int findRepeat(const vi& theVector)
{
  unsigned int lo = 1;
  unsigned int hi = theVector.size() - 1;

  while (lo < hi) {

    unsigned int mid = lo + ((hi - lo) / 2);
    // Scan the whole vector and find out 
    // all the numbers belong to lo->mid range
    unsigned int cnt = 0;
    for (unsigned int item : theVector) {
      if (lo <= item && item <= mid) {
        ++cnt;
      }
    }
    // Assume all numbes in range lo->mid are distinct.
    // Range lo->mid can only hold this number of numbers. 
    unsigned int distinct_cnt = mid - lo + 1;

    //cout << "mid: " << mid << " cnt: " << cnt 
    // << " d: " << distinct_cnt << '\n';
    if (cnt > distinct_cnt) {
      // There must have some number in range lo->mid duplicated.
      hi = mid;
    }
    else {
      // Since the whole vector has the number belong to range lo->mid
      // equals the number in this range. So there is no duplicate 
      // in lo->mid range.
      lo = mid+1;
    }
  }

  return lo;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vi a = {0, 1, 4, 2, 3, 2};
  cout << findDuplicate(a) << '\n';
  cout << findRepeat(a) << '\n';
  return 0;
}
