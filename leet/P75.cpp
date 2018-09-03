#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}
// counting sort
// Accepted
void sortColors(vector<int>& A) {
  vector<int> cnt(3, 0);
  for (auto x:A) {
    if(x==0) cnt[0]++;
    else if(x==1) cnt[1]++;
    else if(x==2) cnt[2]++;
  }
  for (int i=0,k=0; i<3; ++i)
    for(int j=0; j<cnt[i]; ++j)
      A[k++] = i;
  return;
}

void sortColors(vector<int>& A) {
  int zero=0, two=A.size()-1;
  for (int k=0; k<=two;) {
    if(A[k] == 0) swap(A[k++], A[zero++]);
    else if(A[k]==2) swap(A[k], A[two--]);
    else k++;
  }
  return;
}

int main(int argc, char** argv) {
  return 0;
}
