#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
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

// Given a binary tree, find the length of the longest consecutive sequence path.
// The path refers to any sequence of nodes from some starting node to 
// any node in the tree along the parent-child connections. 
// The longest consecutive path need to be from parent to child (cannot be the reverse).
// For example,
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Longest consecutive sequence path is 3-4-5, so return 3.

//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

void dfs(TreeNode* root, int parent, int path, int& res) {
  if (!root) return;

  if (root->val == parent + 1) ++path;
  else path = 1;

  res = max(res, path);
  dfs(root->left, root->val, path, res);
  dfs(root->right, root->val, path, res);
}

class Solution {
public:
  int longestConsecutive(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    dfs(root, -1, 0, res); 
  }
};

int main() {
  return 0;
}
