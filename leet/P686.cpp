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

int repeatedStringMatch(string A, string B) {
  string t = ""; int k = 0;
  while (t.size() < B.size()) {
    t += A;
    ++k;
  }
  if (t.find(B) != string::npos)
    return k;

  t += A; ++k;
  if (t.find(B) != string::npos)
    return k;
  return -1;
}

int main(int argc, char** argv) {
    return 0;
}
