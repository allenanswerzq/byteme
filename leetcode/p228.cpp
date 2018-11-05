#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& aa) {
    vector<string> range;
    for (int i = 0, start = 0; i < aa.size(); ++i) {
      if (i == aa.size() - 1 || aa[i+1] > aa[i] + 1) {
        // Current i is the end of previous range
        range.push_back(to_string(aa[start]));
        if (i > start) range.back() += "->" + to_string(aa[i]);
        // New range start
        start = i + 1;
      }
    }        
    return range;
  }

  vector<string> summaryRanges(vector<int>& aa) {
    vector<string> range;
    int start = 0;
    for (int i = 0; i < aa.size(); ++i) {
      while (i + 1 < aa.size() && aa[i] + 1 == aa[i+1]) ++i;
      // Current i is the end of this range
      range.push_back(to_string(aa[start]));
      if (i > start) range.back() += "->" + to_string(aa[i]);
      start = i + 1;
    }
    return range;
  }
};

int main() {
  return 0;
}
