#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    set<int> st;
    for (int i=0; i<S.size(); ++i)
    if (S[i] == C) st.insert(i);

    vector<int> res;
    for (int i=0; i<S.size(); ++i) {
      if (st.count(i)) res.push_back(0);
      else {
        int t = 10e6;
        for (auto v : st)
        t = min(t, abs(v-i));
        res.push_back(t);
      }
    }
    return res;
  }
};
