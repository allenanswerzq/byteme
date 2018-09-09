#include<bits/stdc++.h>
using namespace std;

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
