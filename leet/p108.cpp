#include<bits/stdc++.h>
using namespace std;

TreeNode* build(vi& aa, int lo, int hi) {
  if (lo > hi) return nullptr;
  if (lo == hi) return new TreeNode(aa[lo]);
  int mid = lo + (hi - lo) / 2;
  TreeNode *root = new TreeNode(aa[mid]);
  root->left = build(aa, lo, mid - 1);
  root->right = build(aa, mid + 1, hi);
  return root;
}

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& aa) {
    int n = sz(aa);
    if (n == 0) return null;
    return build(aa, 0, sz(aa) - 1); 
  }
};

void test() {
  Solution go;
  int r;
  cout(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
