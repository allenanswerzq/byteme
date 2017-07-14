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

int res = INT_MIN;
int dfs(TreeNode* root) {
    if (!root) return 0;
    int l = max(0, dfs(root->left));
    int r = max(0, dfs(root->right));
    res = max(res, l+r+root->val);
    printf("%d %d %d %d\n", root->val, l, r, res);
    return max(l, r) + root->val; 
}

int maxPathSum(TreeNode* root) {
    dfs(root);
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
