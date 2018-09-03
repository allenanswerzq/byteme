#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

vector<int> postorderTraversal(TreeNode* root) {    
  if (!root) return {};

  vector<int> res;
  stack<TreeNode*> stk;
  unordered_map<TreeNode*, bool> mp;
  stk.push(root);
  while (!stk.empty()) {
  TreeNode *top = stk.top();
  if (top->left && mp.find(top->left)==mp.end()) {
    stk.push(top->left);
    mp[top->left] = true;
  }
  else if(top->right && mp.find(top->right)==mp.end()) {
    stk.push(top->right);
    mp[top->right] = true;
  } else {
    stk.pop();
    res.push_back(top->val);
  } 

  }
  return res;
}

vector<int> postorderTraversal(TreeNode* root) {    
  if (!root) return {};

  vector<int> ret;
  stack<TreeNode*> stk;
  TreeNode *last_visited = NULL;
  while (!stk.empty() || root) {
  if (root) {
    stk.push(root);
    root = root->left;
  } else {
    TreeNode *top = stk.top();
    if (top->right && top->right!=last_visited) {
    root = top->right;
    } else {
    stk.pop();
    ret.push_back(top->val);
    last_visited = top;
    root = NULL;
    }
  }
  } 
  return ret;
}

int main(int argc, char** argv) {
  return 0;
}
