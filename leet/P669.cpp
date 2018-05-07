#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
  if (!root) return nullptr;
  if (root->val < L) return trimBST(root->right, L, R);
  if (root->val > R) return trimBST(root->left, L, R);
  TreeNode *cur = new TreeNode(root->val);
  cur->left = trimBST(root->left, L, R);
  cur->right = trimBST(root->right, L, R);
  return cur;
}

int main(int argc, char** argv) {
    return 0;
}
