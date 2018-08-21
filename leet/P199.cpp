#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    vector<TreeNode*> que;   
    TreeNode *last = root;
    que.push_back(root);
    while (!que.empty()) {
        TreeNode *front = que.front();
        que.erase(que.begin());
        if (front->left) que.push_back(front->left);
        if (front->right) que.push_back(front->right);
        if (front == last) {
            res.push_back(last->val);   
            # NOte: how did i know the last node of each level?
            last = que.back();
        }
    }
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
