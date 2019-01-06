#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& aa) {
    map<int, int> mp;
    for (int i = 0; i < aa.size(); ++i) mp[aa[i]]++;    
    int k = 0;
    for (auto it : mp) {
      int y = 1;
      if (it.second >= 2) y = 2; 
      while (y-- > 0)
        aa[k++] = it.first;
    }
    return k;
  }

  int removeDuplicates2(vector<int>& aa) {
    if (aa.size() == 0) return 0;
    int k = 1, cnt = 1, i = 1;
    while (i < aa.size()) {
      if (aa[i] == aa[i - 1]) cnt++;
      else cnt = 1;
      if (cnt <= 2)
        aa[k++] = aa[i];
      i++;
    }
    return k;
  }
};

int main() {
  return 0;
}
