#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// very good approach but not by me
TreeNode *n1, *n2, *prev;
void inOrder(TreeNode* root) {
  if (!root) return;
  inOrder(root->left);
  if(prev) {
  if (!n1 && prev->val > root->val) n1 = prev;
  if (n1 && prev->val > root->val) n2 = root;
  }
  prev = root;
  inOrder(root->right);
}

void recoverTree(TreeNode* root) {
  n1 = n2 = prev = NULL; 
  inOrder(root);
  if (n1 && n2) 
  swap(n1->val, n2->val);
}

int main(int argc, char** argv) {
  return 0;
}
