#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<Interval> merge(vector<Interval>& aa) {
    vector<Interval> ret;
    int n = aa.size();
    if (n <= 0) return ret;
    sort(aa.begin(), aa.end(), [] (const Interval& a, const Interval& b) {
        return a.start < b.start;});
    Interval prev = aa[0];
    for (int i = 1; i < n; ++i) {
      if (prev.start <= aa[i].start && aa[i].start <= prev.end) {
        prev.end = prev.end > aa[i].end ? prev.end : aa[i].end;
      } else {
        ret.push_back(prev);
        prev = aa[i];
      }
    }
    ret.push_back(prev);
    return ret; 
  }

  vector<Interval> insert(vector<Interval>& aa, Interval a) {
    aa.push_back(a);
    return merge(aa);
  }

};

int main() {
  return 0;
}
