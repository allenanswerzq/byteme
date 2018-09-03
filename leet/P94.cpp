#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// recursive solution 
void inorder(vector<int>& res, TreeNode* root) {
  if (!root) return;
  inorder(res, root->left);
  res.push_back(root->val);
  inorder(res, root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  inorder(res, root);
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
