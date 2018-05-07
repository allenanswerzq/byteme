#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

TreeNode* build(vector<int>&num, int lo, int hi) {
    int x = INT_MIN;
    int k = 0;
    for (int i=lo; i<=hi; ++i) 
        if (num[i] > x) {
            x = num[i];
            k = i;
        }
    TreeNode *root = new TreeNode(x);
    if (k > lo)
        root->left = build(num, lo, k-1);
    if (k < hi)
        root->right = build(num, k+1, hi); 
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, 0, nums.size()-1);        
}

int main(int argc, char** argv) {
    return 0;
}
