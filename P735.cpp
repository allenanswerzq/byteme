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

int main(int argc, char** argv) {
  return 0;
}

// Falied 
vector<int> asteroidCollision(vector<int>& asts) {
  vector<int> stk;
  vector<int> ret;
  for (auto x : asts) {
    if (x > 0) 
      stk.push_back(x);
    else if (stk.empty()) {
      ret.push_back(x);
    } else {
      while (!stk.empty() && x<0) {
        int t = stk.back(); stk.pop_back();
        x = abs(x)>t ? x:t; 
        if (x>0) stk.push_back(x);
      }
    } 
  }
  for (auto x : stk)
    ret.push_back(x);
  return ret;
}

// This one is correct
vector<int> asteroidCollision(vector<int>& asts) {
  vector<int> stk;
  for (auto x: asts) {
    if (x > 0)
      stk.push_back(x);
    else {
      bool flag = false; 
      while (stk.size() && stk.back() > 0) {
        int t = abs(a.back()), w = abs(x);
        if (t == w) {
          stk.pop_back();
          flag = true;
          break;
        } else if (t > w) {
          flag = true; 
          break;
        } else {
          stk.pop_back(); 
        }
      }
      if (flag == false) stk.push_back(x);
    } 
  }
  return stk;
}