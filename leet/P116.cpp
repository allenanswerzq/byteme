#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
// but needs extra space
void connect(TreeLinkNode *root) {
  if (!root) return;
  queue<TreeLinkNode*> q;
  q.push(root);
  while (!q.empty()) {
  int n = q.size();
  for (int i=0; i<n; ++i) {
    TreeLinkNode* h = q.front(); q.pop();
    if (i>=0 && i<n-1 && n>1) 
    h->next = q.front();
    
    if (h->left)
    q.push(h->left);
    if (h->right)
    q.push(h->right);
  }
  }
  return ;
}

int main(int argc, char** argv) {
  return 0;
}
