#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

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
