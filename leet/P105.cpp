#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
// recusive approach
TreeNode* build(vector<int>& A, vector<int>& B, int sA, int eA, int sB, int eB) {
  if (sA>eA || sB>eB) return NULL;
  TreeNode* root = new TreeNode(A[sA]);
  int x = -1;
  for (int i=sB; i<=eB; ++i)
    if (B[i] == root->val) {
      x = i;
      break;
    }
  if (x > sB)     // make sure the left side still has elements
    root->left = build(A, B, sA+1, x-sB+sA, sB, x-1);
  else root->left = NULL;
  if (x < eB)     // make sure the right side still has elements
    root->right = build(A, B, x-sB+sA+1, eA, x+1, eB); 
  else root->right = NULL;
  return root;
}

TreeNode* buildTree(vector<int>& A, vector<int>& B) {
  if (A.size()==0 && B.size()==0) return NULL;
  return build(A, B, 0, A.size()-1, 0, B.size()-1);
}
// also has iterative approach

int main(int argc, char** argv) {
  return 0;
}
