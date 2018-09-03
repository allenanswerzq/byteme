#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> res;
  if (!root) return res;

  deque<TreeNode*> dq({root});
  bool dir = false;
  while (!dq.empty()) {
  res.push_back(vector<int>());
  auto level_count = dq.size();
  for (int i=0; i<level_count; ++i) {
    if (dir) {  // right to left


    } else {    // left to right
    auto cur = dq.front(); dq.pop_front();
    result.back().push_back(cur->val);
    if (cur->left)
      dq.push_back(cur->left);
    if (cur->right)
      dq.push_back(cur->right);
    }
  }
  dir = !dir;
  }
  return res;

}

// accepted but not that good approach
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> res;
  if (!root) return res;
  queue<TreeNode*> q;
  vector<int> ans;
  q.push(root);
  q.push(NULL);
  bool mark = false;
  while (!q.empty()) {
  TreeNode* x = q.front(); q.pop();
  if (x == NULL) {
    if(mark) { 
    reverse(ans.begin(), ans.end());
    }
    res.push_back(ans);
    ans.resize(0);
    mark = !mark;
    if(q.size() > 0) 
    q.push(NULL);
  } else {
    ans.push_back(x->val);
    if (x->left) q.push(x->left);
    if (x->right) q.push(x->right);
  }
  }
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
