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

int dominantIndex(vector<int>& a) {
  int idx = max_element(a.begin(), a.end()) - a.begin();
  for (auto &x : a) {
    if (x == a[idx]) continue;
    if (a[idx] < x*2) return -1;
  }
  return idx;
}