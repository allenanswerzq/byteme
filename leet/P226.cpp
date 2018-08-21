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
  return (x && !(x & (x-1)));
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

// recusive 
TreeNode* invertTree(TreeNode* root) {
	if (!root) return NULL;
	TreeNode *left = invertTree(root->left);
	TreeNode *right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}

// iterative 
TreeNode* invertTree(TreeNode* root) {
	if (!root) return NULL;
	stack<TreeNode*> stk;
	stk.push(root);
	while(!stk.empty()) {
		TreeNode *node = stk.top(); stk.pop();
		swap(node->left, node->right);
		if (node->left)
			stk.push(node->left);
		if (node->right)
			stk.push(node->right);
	}
	return root;
}

int main(int argc, char** argv) {
  return 0;
}
