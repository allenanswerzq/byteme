#include<bits/stdc++.h>
using namespace std;
int len(ListNode* root) {
  int ret = 0;
  while (root) root = root->next, ret++;
  return ret;
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {
  vector<ListNode*> res;
  int l = len(root);
  for (int i=0; i<k; ++i) {
  if (root == NULL) {
    res.push_back(NULL);
    continue;
  }

  int n = l/k + (i < l%k);  // very brilliant make true no two parts have a size differing by more than 1 
  res.push_back(root);
  for (int i=0; i<n-1; ++i) root = root->next;
  ListNode *tmp = root->next;
  root->next = NULL;
  root = tmp;  
  }
  return res;
}

int main() {
  return 0;
}

// Use deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> buf;
  vector<int> ret;
  for (auto i=0; i<nums.size(); ++i) {
  // window [i-k+1, i]  
  while (!buf.empty() && nums[i]>nums[buf.back()])
    buf.pop_back(); // buf only save the maximum value for current window
  buf.push_back(i); // put current window maximum value into buf

  if (i >= k-1) // alreay reached window size
    ret.push_back(nums[buf.front()]); // push current window maximum into ret 

  if (buf.front() == i-k+1) // pop the first element of window so we can move on to next iteration 
    buf.pop_front();  
  }
  return ret;
}
