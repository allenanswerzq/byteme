#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  // Ideas: How do we know string p is a permutation of string s?
  // Easy, each character in p is in s too. So the count of each character
  // is same in s and p
  //
  // Need to create a slide window with length of s1
  // NOTE: my method but not true
  bool checkInclusion(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    if ( m > n) return false;
    // vector<int> count(26);
    map<int, int> count;
    for (int i=0; i<m; ++i)
      count[s1[i] - 'a']++;
    for (int i=0; i<n; ++i) {
      count[s2[i] - 'a']--;
      if (i>=m) count[s2[i-m] - 'a']++;
      bool ok = 1;
      for (auto j:count) ok &= j.second == 0;
      if (ok) return true;
    }
    return false;
  }
  bool checkInclusion2(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    if (m > n) return false;
    vector<int> cnt(26);
    vector<int> cur(26);
    for (int i=0; i<m; ++i) {
      cnt[s1[i] - 'a']++;
      cur[s2[i] - 'a']++;
    }
    if (cur == cnt) return true;
    for (int i=1; i<= n-m; ++i) {
      cur[s2[i-1] - 'a']--;
      cur[s2[i+m-1] - 'a']++;
      if (cur == cnt) return true;
    }
    return false;
  }

  bool checkInclusion1(string s1, string s2) {
    do {
      size_t found = s2.find(s1);
      if (found != string::npos)
        return true;
    } while (next_permutation(s1.begin(), s1.end()) );
    return false;
  }
};

int main() {
  string s1 = "ab";
  string s2 = "abcdea";
  Solution s;
  bool ret = s.checkInclusion(s1, s2);
  string out = ret ? "True" : "False";
  cout << out << endl;
  return 0;
}
