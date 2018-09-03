#include<bits/stdc++.h>
using namespace std;

// reference: https://en.wikipedia.org/wiki/Binary_search_tree#Verification
#define ll long long

bool isBST(TreeNode* root, ll mi, ll mx) {
  if (!root) return true;
  if (root->val < mi || root->val > mx) return false;
  return isBST(root->left, mi, root->val - 1) && 
     isBST(root->right, root->val + 1, mx); 
}

bool isValidBST(TreeNode* root) {
  return isBST(root, -(1<<31), (1<<31)-1);
}

int main(int argc, char** argv) {
  return 0;
}
