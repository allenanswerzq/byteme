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

map<int, bool> mp;
bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    if (mp.find(k - root->val) != mp.end())
       return true; 
    else mp[root->val] = true;
    bool l, r;
    l = r = false;
    if (root->left)
        l = findTarget(root->left, k);
    if (root->right)
        r = findTarget(root->right, k);
    return  l || r;
}

int main(int argc, char** argv) {
    return 0;
}
