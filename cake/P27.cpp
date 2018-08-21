#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void reverseWord(string& aa, int lo, int hi) {
  while (lo < hi) {
    swap(aa[lo], aa[hi]);
    ++lo;
    --hi;
  }
}

void reverseMessage(string& message) {
  // Case
  if (message.empty()) return;

  int n = message.size();
  reverseWord(message, 0, n-1);

  int curr=0;
  for (int i=0; i<=n; ++i) {
    if (i==n || message[i] == ' ') {
      reverseWord(message, curr, i-1);
      curr = i+1;
    }
  }
}

int main() {
  string msg = "cake pound steal";
  reverseMessage(msg);
  cout << msg << '\n';
}
