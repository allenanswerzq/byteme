#include<bits/stdc++.h>
using namespace std;

using psi = map<string, int>;

psi helper(string s) {
  if (s.empty()) return psi();
  if (s[0] == '(') {
    int n = 1, i = 1;
    while (i < s.size() && n) {
      if (s[i] == '(') n++;
      else if (s[i]==')') n--;
      i++;
    }

    psi res = helper(s.substr(1, i - 2));
    int num = 0;
    while (i < s.size()&& isdigit(s[i])) num = 10 * num + s[i++] - '0';
    if (num == 0) num = 1;

    for (auto &it : res) it.second *= num;

    psi m = helper(s.substr(i));
    for (auto &it : m) {
      res[it.first] += it.second;
    }
    return res;
  } else {
    psi res;
    int i = 0, num = 0;
    string element = "";
    element += s[i++];
    while (i < s.size() && islower(s[i])) element += s[i++];
    while (i < s.size() && isdigit(s[i])) num = 10*num + s[i++]-'0';
    if (num == 0) num = 1;
    res[element] = num;
    psi m = helper(s.substr(i));
    for (auto &it: m) res[it.first] += it.second
    return res;
  }
}

string countOfAtoms(string s) {
  psi mp = helper(s);
  string ret = "";
  for (auto it: mp) {
    ret += it.first;
    if (it.second > 1) ret += to_string(it.second);
  }
  return ret;
}

int main() {
  return 0;
}
