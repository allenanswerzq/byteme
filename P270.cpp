#include <cstdio>
#include <stdio.h> // for using printf
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
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

// Recusive
int closestValue(TreeNode* root, double target) {
  int a = root->val;
  TreeNode *kid = target < a ? root->left : root->right;
  int b = closestValue(kid, target);
  return abs(a-target) < abs(b-target) ? a : b;
}

// Iterative
int closestValue(TreeNode* root, double target) {
  int closest = root->val;
  while (root) {
    if (abs(closest - taraget) > abs(root->val - target))
      closest = root->val;
    root = target < root->val ? root->left : root->right;
  }
  return closest;
}
