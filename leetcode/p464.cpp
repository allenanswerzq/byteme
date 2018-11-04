#include<bits/stdc++.h>
using namespace std;

// TODO
// mp[state]: 0: unkown, 1: wins, -1: loses.
unordered_map<int, int> mp;

// If the first player wins, returns 1.
// Otherwise returns 0.
bool go(int aa, int bb, int state) {
  if (bb <= 0 ) return 0; 
  if (mp.count(state)) return mp[state] == 1;

  fori (i, 0, aa) {
  // If already visited `i+1`.
  if (state & (1 << i)) continue; 
  // If the opponent lose.
  if (!go(aa, bb - (i + 1), state | (1 << i))) {
    mp[state] = 1;
    return mp[state];
  }
  } 
  // Already tried all possible choices.
  // The first player can not win. 
  mp[state] = -1;
  return 0;
}
 
class Solution {
public:
  bool canIWin(int aa, int bb) {
  // If maxChoose is greater than desiredTotal,
  // The first guy can always win by play optimally.
  if (aa > bb) return 1; 
  // If the sum of all chooseable values is less than
  // desiredTotal number, then no one will win.
  int sum = aa * (aa + 1) / 2;
  if (sum < bb) return 0;
  mp.clear();
  return go(aa, bb, 0);
  }
};

void test(int a, int b) {
  Solution go;
  int r = go.canIWin(a, b);
  cerr(r);    
}

int main() {
   test(4, 6);
  test(10, 11);
  test(10, 40);
  return 0;
}
