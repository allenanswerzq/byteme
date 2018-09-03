#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int scoreOfParentheses(string s) {
  if (s == "") return 0;
  if (s == "()") return 1;
  int v = 0;
  int idx = -1;
  fori(i, 0, sz(s)) {
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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  return 0;
}
