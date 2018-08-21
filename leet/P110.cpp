#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(TreeNode* root) {
    if (!root) return true;
    if (abs(height(root->left) - height(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main(int argc, char** argv) {
    return 0;
}
