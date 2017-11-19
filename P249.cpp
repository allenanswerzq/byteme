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

// Given an array of strings (all lowercase letters), the task is to group them in such a way that all strings in a group are shifted versions of each other. Two string S and T are called shifted if,
// S.length = T.length 
// and
// S[i] = T[i] + K for 
// 1 <= i <= S.length  for a constant integer K
// For example strings {acd, dfg, wyz, yab, mop} are shifted versions of each other.
// Input  : str[] = {"acd", "dfg", "wyz", "yab", "mop",
//                  "bdfh", "a", "x", "moqs"};
// Output : a x
//          acd dfg wyz yab mop
//          bdfh moqs
// All shifted strings are grouped together.
string shift(string s) {
  string t = ""; 
  for (int i=1; i<s.size(); ++i) {
    int diff = s[i] - s[i-1]; // difference between two consecutive characters 
    if (diff < 0) diff += 26; 
    t += 'a' + diff;
  }
  return t;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
  unordered_map<string, vector<string>> mp; 
  vector<vector<string>> group;
  for (auto s : mp) {
    mp[shift[s]] = s;
  } 
  for (auto it : mp) {
    vector<vector<string>> m = it.second; 
    sort(m.begin(), m.end());
    group.push_back(m);
  }
  return group;
}