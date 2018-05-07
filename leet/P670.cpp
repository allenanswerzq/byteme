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
 string a = to_string(num);}

int maximumSwap(int num) {
  string a = to_string(num);        
  int ret = 0;
  int l = a.size();
  for (int i=0; i<l; ++i)
    for (int j=i+1; j<l; ++j) {
      a = to_string(num);
      char t = a[i];
      a[i] = a[j];
      a[j] = t;
      ret = max(ret, stoi(a));
    }
  return ret;
}

int main(int argc, char** argv) {
    return 0;
}
