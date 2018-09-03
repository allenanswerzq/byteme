#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}
// Accepted
int removeDuplicates(vector<int>& A) {
  map<int, int> m;
  for (int i=0; i<A.size(); ++i)
    m[A[i]]++;    
  int k=0;
  // NOTE: iter map operator
  for (auto x: m) {
    int y=1;
    if (x.second >= 2)
       y=2; 
    while(y-- > 0)
      A[k++] = x.first;
  }
  return k;
}

// another approach
// so much pain!!!
int removeDuplicates(vector<int>& A) {
  if(A.size() == 0) return 0;
  int k=1, x=1, y=1;
  while (y < A.size()) {
    if(A[y]==A[y-1]) x++;
    else x=1;
    if (x <= 2)
      A[k++] = A[y];
    y++;
  }
  return k;
}

int main(int argc, char** argv) {
  return 0;
}
