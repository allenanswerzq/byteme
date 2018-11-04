#include<bits/stdc++.h>
using namespace std;
// NOTE: cmp must be static inside a class
static bool cmp(string& s1, string& s2) {
  if (s1.size() == s2.size()) return s1 < s2; // if size equals, return lexicographically smaller
  return s1.size() > s2.size();               // otherwise return longer
}

string longestWord(vector<string>& words) {
  set<string> st;
  for (auto w:words) st.insert(w);
  sort(words.begin(), words.end(), cmp);
  for (auto wd : words) {
  int sz = wd.size();
  string cur = "";
  int flag = 1;
  for (int i=0; i<sz; ++i) {
    cur.push_back(wd[i]);
    if (st.count(cur) == 0) {
    flag = 0; break;
    }
  }
  if (flag) return wd;
  }
  return "";
}

int main() {
  return 0;
}
