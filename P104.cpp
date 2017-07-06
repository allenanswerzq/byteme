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

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Accepted
int maxDepth(TreeNode* root) {
        return root==NULL ? 0:max(maxDepth(root->left), 
                maxDepth(root->right)) + 1;
}

int main(int argc, char** argv) {
    return 0;
}
