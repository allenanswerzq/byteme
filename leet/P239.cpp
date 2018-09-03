#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& aa, int k) {
  deque<int> dq;
  vector<int> ret;
  for (auto i = 0; i < aa.size(); ++i) {
  // Window [i-k+1, i]  
  // dq only save the maximum value for current window
  while (!dq.empty() && aa[i] > aa[dq.back()])
  dq.pop_back(); 

  // Put current window maximum value into dq
  dq.push_back(i); 

  // Already reaches window size
  // Push current window maximum into ret 
  if (i >= k-1) 
  ret.push_back(aa[dq.front()]); 
  
  // Pop the first element of window so we can move on to next iteration 
  if (dq.front() == i - k + 1) 
  dq.pop_front();  
  }
  return ret;
  }
};

int main(int argc, char** argv) {
  return 0;
}
