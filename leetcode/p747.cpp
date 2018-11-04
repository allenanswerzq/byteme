#include<bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int>& a) {
  int idx = max_element(a.begin(), a.end()) - a.begin();
  for (auto &x : a) {
  if (x == a[idx]) continue;
  if (a[idx] < x*2) return -1;
  }
  return idx;
}
