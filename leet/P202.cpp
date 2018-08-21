#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

bool isHappy(int n) {
  map<int, int> mp;        
  int sum = 0;
  while(sum!=1 && mp.find(n)==mp.end()) {
    string a = to_string(n);
    for (int i=0; i<a.size(); ++i)
      sum += (a[i]-'0') * (a[i]-'0');
    mp[n] = sum;
    n = sum;
  }
  return sum == 1;
}

int main(int argc, char** argv) {
    return 0;
}
