#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) {
    vvi res;
    for (int i=0; i<sz(S); ) {
      int j = i;
      while(j < sz(S)-1 && S[j] == S[j+1]) ++j;
      if (j - i + 1 >= 3) res.pb({i, j});
      i = j+1;
    }
    return res;
  }
};

int main() {
  return 0;
}
