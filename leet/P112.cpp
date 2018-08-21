#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}


// Accepte
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right && root->val == sum)
        return true;
    return hasPathSum(root->left, sum-root->val) ||
            hasPathSum(root->right, sum-root->val);
}

int main(int argc, char** argv) {
    return 0;
}
