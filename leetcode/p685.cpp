#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
  class Node {
    public:
    int val;
    int rank;
    Node* parent;
    Node(int inp) : val(inp) { parent = this; rank = 0; }
  };

public:
  void make_set(int inp) {
    Node* n = new Node(inp);
    dsets.pb(n);
    dset_size = sz(dsets);
  }

  void joint(int x, int y) {
    link(find_set(x), find_set(y));
  }

  void link(Node* x, Node* y) {
    // trace("link", x->val, y->val);
    if (x->rank > y->rank) y->parent = x;
    else x->parent = y;
    if (x->rank == y->rank)
      ++x->rank;
  }

  Node* find_set(int inp) {
    // Note: 0 based index.
    --inp;
    if (inp >= dset_size) {
      trace("Exceed the range of the DisjointSet.");
      trace(dset_size);
      return null;
    }
    return _find_set(dsets[inp]);
  }

  Node* _find_set(Node* x) {
    if (x != x->parent) {
      x->parent = _find_set(x->parent);
    }
    return x->parent;
  }

  int groups() {
    int res = 0;
    unordered_set<Node*> st;
    fora(node, dsets) {
      Node *parent = _find_set(node);
      if (!st.count(parent)) {
      ++res;
      st.insert(parent);
      }
    }
    return res;
  }

private:
  vector<Node*> dsets;
  int dset_size;
};

// TODO
class Solution {
public:
  vector<int> findRedundantDirectedConnection(vvi& edges) {
    int n = sz(edges);
    vi parent(n + 1, 0), edge_a, edge_b;
    // Find a node that has two parents.
    fora (e, edges) {
      int src = e[0], dst = e[1];
      if (parent[dst] == 0) {
        parent[dst] = src;
      } else {
        // Possible invalid edges.
        edge_a = {parent[dst], dst};
        edge_b = e;
        // We explicitly changed it right.
        e[1] = 0;
      }
    }

    DisjointSet djs;
    fori (i, 0, n) djs.make_set(i);
    fora (e, edges) {
      // Ignore the edge that makes extra parents and see
      // whether we can get a valid tree or not.
      if (e[1] == 0) continue;
      int src = e[0], dst = e[1];
      if (djs.find_set(src) != djs.find_set(dst))
      djs.joint(src, dst);
      else
      if (sz(edge_a)) return edge_a;
      // No one has two parents, but there exist a cycle in
      // graph so it's also invalid.
      else return e;
    }
    return edge_b;
  }
};

int main() {
  return 0;
}
