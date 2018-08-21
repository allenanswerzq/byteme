#include<bits/stdc++.h>

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
    // dfs
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (mp.find(node) == mp.end()) {
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
