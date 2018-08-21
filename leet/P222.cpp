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

// recursive approach
int height(TreeNode *root) {
	return root==NULL ? 0: 1+height(root->left);
}

int countNodes(TreeNode* root) {
	int h = height(root);
	return h <= 0 ? 0:
				 height(root->right)==h-1 ? ((1<<h-1) -1 +1) + countNodes(root->right):  // left and right subtree have same height
				 														((1<<h-2) -1 +1) + countNodes(root->left);		// left subtree height greater one than right subtree 
				 														// left subtree nodes + root node + right tree nodes
}

// iterative approach
int countNodes(TreeNode* root) {
	if(root == NULL) return 0;
	int h = 0;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	while (right != NULL) {
		left = left->left;
		right = right->right;
		h++;
	}
	if (left == NULL) // left subtrees and right subtrees are all complete binary tree
		return ((1<<h+1) -1);
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(int argc, char** argv) {
  return 0;
}
