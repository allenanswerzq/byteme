#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
    printf("%d ", x); 
  printf("]\n");
}


void run(TreeNode* cur, set<int>& A) {
  if (!cur) return;
  A.insert(cur->val);
  run(cur->left, A);
  run(cur->right, A);
}

int findSecondMinimumValue(TreeNode* root) {
  set<int> A;
  run(root, A);
  if (A.size() < 2) return -1;
  auto it = A.begin();
  ++it;
  return *it;
}

int main(int argc, char** argv) {
  return 0;
}
