#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

// Really awesome approach
// Use istringstream so we dont need to parse nums
string fractionAddition(string expression) {
  istringstream in(expression);
  int A = 0, B = 1, a, b;
  char _;
  while (in >> a >> _ >> b) {
    A = A * b + a * B;
    B *= b;
    int g = abs(__gcd(A, B));
    A /= g;
    B /= g;
  }
  return to_string(A) + '/' + to_string(B);
}

int main() {
  return 0;
}
