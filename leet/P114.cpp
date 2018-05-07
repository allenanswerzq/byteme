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

// Perfect
// Accepted
void flatten(TreeNode* root) {
    if (!root) return;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    flatten(left);
    flatten(right);
    TreeNode* p = root->left;
    while (p && p->right)
        p = p->right;
    if (p) {
        p->right = right;
        root->right = left;
        root->left = NULL;
    } 
    return ;
}

int main(int argc, char** argv) {
    return 0;
}
