#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// recusive approach
bool helper(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    return q->val==q->val && 
            helper(p->left, q->right) && helper(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    return root==NULL || helper(root->left, root->right);
}

// iterative approach
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q1, q2;

    TreeNode *left, *right;
    q1.push(root->left);
    q2.push(root->right);
    while (q1.empty()==false && q2.empty()==false) {
        left = q1.front(); q1.pop();
        right = q2.front(); q2.pop();
        if (!left && !right) continue;
        if (!left || !right) return false; 
        if (left->val != right->val) return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
    return true;
}

int main(int argc, char** argv) {
    return 0;
}
