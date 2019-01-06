#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}
// Perfect!!!
// It accepted
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
  if (!t1) return t2;
  if (!t2) return t1;
  if (t1 && t2) t1->val += t2->val; 
  t1->left = mergeTrees(t1->left, t2->left);
  t1->right = mergeTrees(t1->right, t2->right);
  return t1;  
}

int main() {
  return 0;
}
