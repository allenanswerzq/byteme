#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
TreeNode* build(vector<int>& nums, int start, int end) {
  if (start > end) return NULL;
  int x = start + (end-start+1)/2;
  TreeNode *root = new TreeNode(nums[x]);
  root->left = build(nums, start, x-1);
  root->right = build(nums, x+1, end);
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  int n = nums.size();
  if (n == 0) return NULL;
  return build(nums, 0, n-1);
  
}

int main(int argc, char** argv) {
  return 0;
}
