#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
  set<int> st;
  for (int i=0; i<S.size(); ++i)
  if (S[i] == C)
    st.insert(i);

  vector<int> res;
  for (int i=0; i<S.size(); ++i)
  if (st.count(i))
    res.push_back(0);
  else {
    int t = 10e6;
    for (auto v : st)
    t = min(t, abs(v-i));
    res.push_back(t);
  }
  return res;
  }
};
