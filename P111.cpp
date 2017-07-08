#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>   // std:string std:stoi
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int res = INT_MAX;
    if (root->left)
        res = min(res, minDepth(root->left));
    if (root->right)
        res = min(res, minDepth(root->right));
    return 1 + res;
}

int minDepth(TreeNode* root) {
    if (!root) return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    return 1 + (min(L, R) ? min(L, R) : max(L, R));
}

int main(int argc, char** argv) {
    return 0;
}
