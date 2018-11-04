#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) {
    if (s == "") return 0;
    if (s == "()") return 1;
    int v = 0, idx = -1;
    fori (i, 0, sz(s)) {
      if (s[i] == '(') ++v;
      else --v;

      if (v == 0) {
        if (i == sz(s)-1)
          return 2 * scoreOfParentheses(s.substr(1, sz(s)-2));
        return scoreOfParentheses(s.substr(0, i+1)) +
             scoreOfParentheses(s.substr(i+1));
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
