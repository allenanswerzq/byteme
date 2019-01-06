#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& aa) {
    set<int> st;
    for (int i = 0; i < aa.size(); ++i) {
      if (st.count(aa[i]))
        return 1;
      st.insert(aa[i]);
    }
    return 0;
  }
};

int main() {
  return 0;
}
