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

class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int mx = 0;
    deque<pair<TreeNode*, int>> q;
    q.pb({root, 1});
    while (sz(q)) {
      int n = sz(q);
      int lo = q.fr().se;
      int hi = lo;
      fori (i, 0, n) {
        auto cur = q.fr(); q.ppf();
        TreeNode *node = cur.fi;
        hi = cur.se;
        if (node->left) q.pb({node->left, 2 * hi});
        if (node->right) q.pb({node->right, 2 * hi + 1});
      }
      mx = max(mx, hi - lo + 1);
    }
    return mx;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
