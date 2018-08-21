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

TreeNode* res;
int mx;

int dfs(TreeNode* root, int depth) {
  if (!root) return depth;
  int a = dfs(root->left, depth + 1);
  int b = dfs(root->right, depth + 1);
  if (a == b && a >= mx) {
    mx = a;
    res = root;
  }
  return max(a, b);
}

class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if (!root) return nullptr;
    res = nullptr;
    mx = -1;
    dfs(root, 0);
    return res;        
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p865-small.txt", "rt", stdin);
  clock_t begin = clock();



  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
