#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
// BFS approach
TreeNode* addOneRow(TreeNode* root, int v, int d) {
  if (d == 1) {
  TreeNode *h = new TreeNode(v);
  h->left = root;
  return h;
  }
  vector<TreeNode*> stk;
  stk.push_back(root);
  int curRow = 1;
  while (!stk.empty()) {
  if (currRow == d-1) {
    while (!stk.empty()) {
    TreeNode *h = stk.back();
    stk.pop_back();
    TreeNode *l = h->left;
    TreeNode *r = h->right;
    h->left = new TreeNode(v);
    h->right = new TreeNode(v);
    h->left->left = l;
    h->right->right = r;
    }
    return root;
  } else {
    int n = stk.size();
    for (auto h: stk) {
    if(h->left) stk.push_back(h->left);
    if(h->right) stk.push_back(h->right);
    }
    stk.erase(stk.begin(), stk.begin()+n);
    curRow++;
  }
  }
  
  return NULL;
}
// recusion approach
TreeNode* addOneRow(TreeNode* root, int v, int d) {
  if (d == 1) {
  TreeNode *h = new TreeNode(v);
  h->left = root;
  return h;
  }
  if(!root) return null;
  if(d == 2){
  TreeNode *a = new TreeNode(v);
  TreeNode *b = new TreeNode(v);
  a->left = root->left;
  b->right = root->right;
  root->left = a;
  root->right = b;
  return root;
  }

  root->left = addOneRow(root->left, v, d-1);
  root->right = addOneRow(root->right, v, d-1);
  return root;
}

int main(int argc, char** argv) {
  return 0;
}
