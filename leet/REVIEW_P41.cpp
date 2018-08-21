#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

class Solution
{
public:
  int firstMissingPositive(int A[], int n)
  {
    for(int i = 0; i < n; ++ i)
      while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
        swap(A[i], A[A[i] - 1]);
      
    for(int i = 0; i < n; ++ i)
      if(A[i] != i + 1)
        return i + 1;
      
      return n + 1;
  }
};

int main(int argc, char** argv) {
    return 0;
}
