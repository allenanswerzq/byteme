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

// TODO
// int go(TreeNode* root, int pre_sum, int goal, 
//        unordered_map<int, int>& mp) {
//   if (!root) return 0;
//   pre_sum += root->val;
//   // prefix_sum_now - goal = prefix_sum_last
//   // prefix_sum_now - prefix_sum_last = goal
//   int res = mp[pre_sum - goal];
//   mp[pre_sum]++;
//   res += go(root->left, pre_sum, goal, mp) +
//          go(root->right, pre_sum, goal, mp);
//   // Note: this line plays a important role here.
//   mp[pre_sum]--;
//   return res;
// }

// class Solution {
// public:
//   int pathSum(TreeNode* root, int goal) {
//     if (!root) return 0;
//     unordered_map<int, int> mp;
//     mp[0] = 1;
//     return go(root, 0, goal, mp);
//   } 
// };

int res;
void dfs(TreeNode* root, int sum, vi &path) {
  if (!root) return;
  path.pb(root->val);
  int tmp = 0;
  ford (i, sz(path) - 1, -1) {
  tmp += path[i];
  if (tmp == sum) ++res;
  }
  dfs(root->left, sum, path);
  dfs(root->right, sum, path);
  // We must pop the back element out, since when we
  // go back to the up caller, he can't see this value.
  path.ppb();
}

class Solution {
public:
  int pathSum(TreeNode* root, int goal) {
  if (!root) return 0;
  res = 0;
  vi path;
  dfs(root, goal, path);
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
