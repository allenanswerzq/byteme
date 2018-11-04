#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int kSimilarity(string A, string B) {
  int n = sz(A);
  deque<pair<string, int>> deq;
  deq.eb(A, 0);

  while(!deq.empty()) {
    auto t = deq.back(); deq.ppb();
    if (t.fi == B) return t.se;

    int idx;
    fori(i, 0, n) { 
    if (t.fi[i] == B[i]) continue;
    else {
      idx = i;
      break;  
    }

    fori(i, idx+1, n)
    if (B[idx] == t.fi[i]) {
      string tmp = t.fi;
      swap(tmp[i], tmp[idx]);
      deq.push_front(mk(tmp, t.se + 1)); 
    }
  }

  return -1;
  }
};

int main() {
   return 0;
}
