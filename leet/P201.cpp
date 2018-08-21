#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}
// naive way tle
int rangeBitwiseAnd(int m, int n) {
        int res = -1;
        for (int i=m; i<=n; ++i)
            res &= i;
        return res;
}

int rangeBitwiseAnd(int m, int n) {
  return n>m ? (rangeBitwiseAnd(m>>1, n>>1) << 1) : m;
}

int main(int argc, char** argv) {
    return 0;
}
