#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

class Solution {
public:
  bool isAnagram(string ss, string tt) { 
    if (sz(ss) != sz(tt)) return false;     
    unordered_map<char, int> mp;
    for (int i = 0; i < ss.size(); ++i) {
      mp[ss[i]]++;
      mp[tt[i]]--;
    }
    for (auto it : mp)
      if (it.second > 0)
        return false;
    return true;
  }
};

int main() {
  return 0;
}
