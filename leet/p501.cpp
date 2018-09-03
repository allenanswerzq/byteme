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


vi res;
int pre;
int cnt;
int mx; 

void traverse(TreeNode *root) {
  if (!root) return;
  traverse(root->left);
  if (root->val == pre) ++cnt;
  else cnt = 1;
  if (cnt > mx) {
  mx = cnt;
  res.clear();
  res.pb(root->val);
  } else if (cnt == mx) {
  res.pb(root->val);
  }
  pre = root->val;
  traverse(root->right);
}

class Solution {
public:
  vector<int> findMode(TreeNode* root) {
  res.clear();
  if (!root) return res;     
  mx = 0;
  cnt = 0;
  pre = nnf;
  traverse(root);
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
