#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// recusive approach
int maxA(int N) {
  int res;
  for (int i=1; i<N; ++i) 
  res = max(res, maxA(i)*(N-i-1));
  return res;
}

// dp approach
int maxA(int N) {
  
}

int main(int argc, char** argv) {
  return 0;
}
