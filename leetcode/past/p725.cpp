#include <bits/stdc++.h>
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
    if (root == nullptr) {
      res.push_back(nullptr);
      continue;
    }

    int n = l / k + (i < l % k);
    res.push_back(root);
    for (int i = 0; i < n - 1; ++i) root = root->next;
    ListNode *tmp = root->next;
    root->next = nullptr;
    root = tmp;
  }
  return res;
}

vi maxSlidingWindow(vi& aa, int k) {
  deque<int> buf;
  vector<int> ret;
  for (auto i=0; i<aa.size(); ++i) {
    // window [i-k+1, i]
    while (!buf.empty() && aa[i]>aa[buf.back()]) buf.pop_back();
    buf.push_back(i);

    if (i >= k-1) ret.push_back(aa[buf.front()]);

    if (buf.front() == i-k+1) buf.pop_front();
  }
  return ret;
}
