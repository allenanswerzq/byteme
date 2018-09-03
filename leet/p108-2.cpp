#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* build(vi& aa, int lo, int hi) {
  if (lo > hi) return null;
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
