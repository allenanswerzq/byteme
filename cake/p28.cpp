#include<bits/stdc++.h>
using namespace std;

int findParenthesis(string aa, int k) {
  int cnt = 0;
  int n = aa.size();
  for (int i=k+1; i<n; ++i) {
    if (aa[i] == '(')
      ++cnt;
    else if (aa[i] == ')') {
      if (cnt == 0)
        return i;
      else
        --cnt;
    }
  }
  return -1;
}

int main() {
  return 0;
}
