#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

// level order traversal
// accepted
vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> res;
  if (!root) return res;
  vector<TreeNode*> queue;
  vector<int> ans;
  queue.push_back(root);
  int level=1, x=0, y=1, y_next=0;
  while (!queue.empty()) {
    TreeNode* tmp = queue.front();
    queue.erase(queue.begin());
    ans.push_back(tmp->val);
    x++;    // current level's node count
    if(tmp->left) {
      queue.push_back(tmp->left);
      y_next++;
    }
    if(tmp->right) {
      queue.push_back(tmp->right);
      y_next++;
    }

    if(x == y ) { // y stands for current level nodes sum
      level++;
      res.push_back(ans);
      ans.clear();
      x = 0;
      y = y_next;
      y_next = 0;
    }
  }
  return res;
}
// also have tww kinds more concise approach
// and one preorder apparoch
vector<vector<int>> levelOrder(TreeNode* root) {
}

int main(int argc, char** argv) {
  return 0;
}
