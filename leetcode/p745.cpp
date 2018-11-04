#include<bits/stdc++.h>
using namespace std;

class WordFilter {
  unordered_map<string, int> m;
public:
  // apple
  // ''+'$'+''  ''+'$'+'e'  ''+'$'+'el' .... ''+'$'+'elppa'
  // 'a'+'$'+'' 'a'+'$'+'e' 'a'+'$'+'el' ... 'a'+'$'+'elppa'
  // ...
  // 'apple'+'$'+'e'   .... 'apple'+'$'+'elppa'

  WordFilter(vector<string> words) {
  int no = 0;
  for (auto &s : words) {
    const int n = s.size();
    string a = "";
    for (int i = 0; i <= n; ++i) {
    if (i)
      a += s[i - 1];
    string b = "";
    for (int j = 0; j <= n; ++j) {
      if (j)
      b += s[n - j];
      m[a + "$" + b] = no;
    }
    }
    no++;
  }
  }

  int f(string prefix, string suffix) {
  string s = prefix + "$" + string(suffix.rbegin(), suffix.rend());
  if (!m.count(s))
    return -1;
  return m[s];
  }
};
