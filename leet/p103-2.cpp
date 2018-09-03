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
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vvi res;
  if(!root) return res;
  deque<TreeNode*> q;
  int level = 0;
  q.pb(root);
  while (sz(q)) {
  int n = sz(q);
  vi tmp;
  ++level;
  fori (i, 0, n) {
  auto cur = q.fr(); q.ppf(); 
  if (level % 2) tmp.pb(cur->val);
  else tmp.insert(tmp.begin(), cur->val);
  if (cur->left) q.pb(cur->left);
  if (cur->right) q.pb(cur->right);
  }
  res.pb(tmp);
  }
  return res;
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
