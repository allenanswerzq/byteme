#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}
// easy one
// accepted
bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p || !q) {
    if (!p && !q) return true;
    else return false;
  }
  if (p->val != q->val) return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char** argv) {
  return 0;
}
