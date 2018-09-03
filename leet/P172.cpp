#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

typedef long long int64;
int trailingZeroes(int n) {
  return n == 0 ? 0: n/5 + trailingZeroes(n/5);
}

int main(int argc, char** argv) {
  return 0;
}
