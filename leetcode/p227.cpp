#include <bits/stdc++.h>
using namespace std;

#define ll long long

// TODO
class Solution {
public:
  int calculate(string ss) {
    istringstream iss('+' + ss + '+');
    ll total = 0, term = 0;
    char op;
    while (iss >> op) {
      if (op == '+' || op == '-') {
        total += term;
        iss >> term;
        term *= (op == '-') ? -1 : 1;
      } else {
        int tmp;
        iss >> tmp;
        if (op == '*') term *= tmp;
        if (op == '/') term /= tmp; 
      }
    }
    return total;
  }
};

int main() {
  return 0;
}
