#include <cstdio>
#include <stdio.h> // for using printf
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
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

// dont fully understand need review
vector<int> majorityElement(vector<int>& nums) {
  int n = nums.size();
  if (n <= 0) return {};
  int c1=0, c2=0, candidate1=0, candidate2=1;
  for (auto x: nums) {
    if (x == candidate1)
      c1++;
    else if (x == candidate2)
      c2++;
    else if (c1 == 0) {
      candidate1 = x;
      c1 = 1;
    } else if (c2 == 0) {
      candidate2 = x;
      c2 = 1;
    } else {
      c1--;
      c2--;
    }
  }

  int n1=0, n2=0;
  for (auto x: nums) {
     if (x == candidate1) n1++;
     if (x == candidate2) n2++;
  }
  vector<int> res;
  if (n1 > n/3) res.push_back(candidate1);
  if (n2 > n/3) res.push_back(candidate2);
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
