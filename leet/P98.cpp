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

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// reference: https://en.wikipedia.org/wiki/Binary_search_tree#Verification
bool isBST(TreeNode* root, long long minKey, long long maxKey) {
    if (!root) return true;
    if (root->val<minKey || root->val>maxKey) return false;
    return isBST(root->left, minKey, (long long)root->val-1) 
            && isBST(root->right, (long long)root->val+1, maxKey); 
}

bool isValidBST(TreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main(int argc, char** argv) {
    return 0;
}
