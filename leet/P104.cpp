#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
int maxDepth(TreeNode* root) {
  return root==NULL ? 0 : max(maxDepth(root->left), 
                              maxDepth(root->right)) + 1;
}

int main(int argc, char** argv) {
    return 0;
}
