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
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        for (auto n : node->neighbors) {
            // why this not correct???
            // 5/12 test cases passed
            if (n != node)
                root->neighbors.push_back(cloneGraph(n));
            else root->neighbors.push_back(root);
        }
        return root; 
    }

    // dfs
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (mp.find(node) == m.end()) {
            mp[node] = new UndirectedGraphNode(node->label);
            for (auto n : node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return mp[node]; 
    }

};

int main(int argc, char** argv) {
    return 0;
}
