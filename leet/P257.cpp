#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

vector<string> binaryTreePaths(TreeNode* root) {
  if (!root) return {};
  if (!root->left && !root->right) return {to_string(root->val)};
  vector<string> ret;  
  vector<string> left = binaryTreePaths(root->left);
  vector<string> right = binaryTreePaths(root->right);
  for (auto s : left) {
    s = to_string(root->val) + "->" + s;
    ret.push_back(s);
  } 
  for (auto s : right) {
    s = to_string(root->val) + "->" + s;
    ret.push_back(s);
  } 
  return ret;
}

def binaryTreePaths(self, root):
    if not root:
        return []
    return [str(root.val) + '->' + path
            for kid in (root.left, root.right) if kid
            for path in self.binaryTreePaths(kid)] or [str(root.val)]
