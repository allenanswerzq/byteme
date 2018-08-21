#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool isParindrome(string& a) {
  set<char> st;
  fora(ch, a) {
    if (st.count(ch))
      st.erase(ch);
    else 
      st.insert(ch);
  }
  return st.size() <= 1;
}

int main() {
  string a("ciivc");
  cout << isParindrome(a) << '\n';
  return 0;
}
