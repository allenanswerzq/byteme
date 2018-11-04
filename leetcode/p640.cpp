#include<bits/stdc++.h>
using namespace std;

pair<double, double> parse(string str) {
  // ----start ----- end---
  // ---- +   73234   +
  int start=0, end=1;
  pair<double, double> res;
  for (; start != str.length(); start = end) {
    for (end=start+1, end<str.length() && str[end]!='+' &&
        str[end]!='-'; ++end);
    int sign = 1;
    if (str[start] == '+') start++;
    else if (str[start] == '-') {
      start++;
      sign = -1;
    }

    if (str[end-1] == 'x') {
      if (end-1>start)
        res.first += sign*stod(str.substr(start, end-start-1));
      else
        res.first += sign;
    } else {
      res.second += sign*stod(str.substr(start, end-start));
    }

  }
  return res;
}

string solves(string s) {
  int idx = 0;
  for (; idx<s.length(); ++idx)
    if (s[idx] == '=')
      break;
  if (idx == s.length()) return "Infinite solutions";
  pair<double, double> left = parse(s.substr(0, idx));
  pair<double, double> right = parse(s.substr(idx+1));

  double xe = left.first - right.first;
  double ce = right.second - left.second;

  if (xe == 0)
    return ce==0 ? "Infinite solutions":"No solution";
  int d = ce/xe;
  return "x=" + to_string(d);

}

int main() {
  return 0;
}
