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

vector<TreeNode*> create(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }
    for (int x=start; x<=end; ++x) 
        for (auto left: create(start, x-1))
            for (auto right: create(x+1, end)) {
                TreeNode* root = new TreeNode(x);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
    return trees; 
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if (n != 0)
        res = create(1, n);
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
