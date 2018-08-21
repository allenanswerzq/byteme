#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
 string a = to_string(num);}

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

int main(int argc, char** argv) {
    return 0;
}
