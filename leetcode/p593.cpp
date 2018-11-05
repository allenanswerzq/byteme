#include <bits/stdc++.h>
using namespace std;

// Why this code does not work???
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
  int d1 = DIST(p1, p2);
  int d2 = DIST(p1, p3);
  int d3 = DIST(p1, p4);
  if ((d1==d2 && d3==N*d2) ||
      (d1==d3 && d2==N*d1) ||
      (d2==d3 && d1==N*d2))
    return true;
  return false;
}

int main() {
  return 0;
}
