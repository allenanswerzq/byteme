#include<bits/stdc++.h>
using namespace std;

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
  if (!node) return nullptr;
  if (!mp.count(node)) {
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
