#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
    printf("%d ", x);
  printf("]\n");
}

int repeatedStringMatch(string A, string B) {
  string t = ""; int k = 0;
  while (t.size() < B.size()) {
  t += A;
  ++k;
  }
  if (t.find(B) != string::npos)
  return k;

  t += A; ++k;
  if (t.find(B) != string::npos)
  return k;
  return -1;
}

int main(int argc, char** argv) {
  return 0;
}
