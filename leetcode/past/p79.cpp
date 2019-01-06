#include <bits/stdc++.h>
using namespace std;

#define vc vector<char>
#define vvc vector<vc>

class Solution {
public:
  bool check(vvc& aa, int x, int y, string word) {
    if (word.size() == 0) return true;
    if (! (0<=x && x<aa.size() && 0<=y && y<aa[0].size()) || 
        aa[x][y] != word[0])
      return false; 
    
    // Mark current cell.
    aa[x][y] = 0; 
    string tmp = word.substr(1);
    if (check(aa, x, y+1, tmp) || check(aa, x, y-1, tmp) ||
        check(aa, x-1, y, tmp) || check(aa, x+1, y, tmp))
      return true;
    aa[x][y] = word[0];
    return false;
  }

  bool exist(vvc& aa, string word) {
    for (int i = 0; i < aa.size(); ++i)
      for (int j = 0; j < aa[0].size(); ++j)
        if (check(aa, i, j, word)) 
          return true;
    return false;
  }
};

int main() {
  return 0;
}
