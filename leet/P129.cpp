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

int res = 0;
void dfs(TreeNode* root, int x) {
    if(!root) return ;

    x = 10*x + root->val;
    // if current node is leaf node
    if (!root->left && !root->right) {
        res += x;
        return ;
    }

    dfs(root->left, x);
    dfs(root->right, x);
}

int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    dfs(root, 0); 
    return res;
}

int main(int argc, char** argv) {
    return 0;
}
