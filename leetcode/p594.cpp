#include<bits/stdc++.h>

using namespace std;

printVector(vector<int>& v) {
  cout << "[ ";
  for (int x:v)
      cout << x << " ";
  cout <<"] " << endl;
}

// Hash Table Approach
int findLHS(vector<int>& A) {
  map<int, int> cnt;
  int ret = 0;
  for (auto x : A) 
    cnt[x]++;
  
  /*for (auto it=cnt.begin(); it!=cnt.end(); ++it) {
    if (cnt.find(it->first + 1) != cnt.end()) {
      ret = max(ret, it->second + cnt[it->first + 1]);
    }
  }*/
  for (auto x:cnt) {
    if(cnt.find(x.first+1) != cnt.end()) {
      ret = max(ret, x.second+cnt[x.first+1]);
    }
  }
  return ret;
    
}

int main() {
  int n[] = {1,3,2,2,5,2,3,7};
  vector<int> v(n, n+8);
  cout << findLHS(v) << endl;
  return 0;
}
