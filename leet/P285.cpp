#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

//Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
TreeNode* inorderSuccessor(TreeNode* root, TreeNode *p) {
	if (!root) return nullptr;	
	if (p->val >= root->val) 
		return inorderSuccessor(root->right, p);
	else {
		TreeNode *left = inorderSuccessor(root->left, p);	
		return left==nullptr ? root : left;	
	}
}