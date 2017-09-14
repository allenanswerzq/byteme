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

bool isHappy(int n) {
  map<int, int> mp;        
  int sum = 0;
  while(sum!=1 && mp.find(n)==mp.end()) {
    string a = to_string(n);
    for (int i=0; i<a.size(); ++i)
      sum += (a[i]-'0') * (a[i]-'0');
    mp[n] = sum;
    n = sum;
  }
  return sum == 1;
}

int main(int argc, char** argv) {
    return 0;
}
