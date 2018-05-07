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

bool isIsomorphic(string s, string t) {
  map<char, char> a;
  map<char, char> b;
  for (int i=0; i<s.size(); ++i) {
    if (a.find(s[i])==a.end() && b.find(t[i])==b.end()) {
      a[s[i]] = t[i];
      b[t[i]] = s[i];
    } else {
      if (a[s[i]] != t[i]) return false; 
    }
  }
  return true;
}

int main(int argc, char** argv) {
    return 0;
}
