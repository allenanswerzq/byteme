#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
  string a = to_string(num);        
  int ret = 0;
  int l = a.size();
  for (int i=0; i<l; ++i)
  for (int j=i+1; j<l; ++j) {
    a = to_string(num);
    char t = a[i];
    a[i] = a[j];
    a[j] = t;
    ret = max(ret, stoi(a));
  }
  return ret;
}

int main() {
  return 0;
}
