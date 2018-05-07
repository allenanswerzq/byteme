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

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;        
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        double sum = 0;
        int n = q.size();
        for (auto i=0; i<n; ++i) {
            TreeNode* x = q.front(); 
            q.pop();
            sum += x->val;
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        res.push_back(sum / n);
    }
    return res;
}
int main(int argc, char** argv) {
    return 0;
}
