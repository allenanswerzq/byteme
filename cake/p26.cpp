#include<bits/stdc++.h>
using namespace std;

void reverse(string& aa) {
  // Case
  if (aa == "") return "";
  int n = aa.size();
  int lo=0, hi=n-1;
  while (lo < hi) {
    swap(aa[lo], aa[hi]);
    ++lo;
    --hi;
  }
}

int main() {
  return 0;
}
