#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Node {
public:
  int val;
  int rank;
  Node* parent;
  Node(int inp)
  : val(inp) {
    parent = this;
    rank = 0;
  }
};

class DisjointSet
{
public:
  void makeSet(int inp) {
  Node* n = new Node(inp);
  sets.pb(n);
  } 

  void joint(int x, int y) {
  link(findSet(sets[x]), findSet(sets[y]));
  }

  void link(Node* x, Node* y) {
  // cout << x->val << " " << y->val << endl;
  if (x->rank > y->rank)
    y->parent = x;
  else
    x->parent = y; 
  if (x->rank == y->rank)
    ++x->rank;
  }

  Node* findSet(Node* x) {
  if (x != x->parent) {
    x->parent = findSet(x->parent);
  }
  return x->parent;
  }

  int size() {
  int res = 0;
  unordered_set<Node*> st;
  fora(node, sets) {
    Node *par = findSet(node);
    if (!st.count(par)) {
    ++res;
    st.insert(par);
    }
  }
  return res;
  }

private:
  vector<Node*> sets;
};

bool isSimilar(string a, string b) {
  int n = sz(a);
  int cnt = 0;
  int res = 0;
  fori(i, 0, n) 
  if (a[i] != b[i]) {
    ++cnt;
    res += (a[i] - b[i]);
    if (cnt > 2) return false;
  }
  return (cnt==0) || (cnt == 2 && res == 0);
}

class Solution {
public:
  int numSimilarGroups(vector<string>& A) {
  int n = sz(A);
  DisjointSet ds;
  fori(i, 0, n)
    ds.makeSet(i); 

  fori(i, 0, n) 
    fori(j, i+1, n) {
    if (isSimilar(A[i], A[j])) {
      ds.joint(i, j); 
    }
    }
  return ds.size();
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  Solution go;
  vs v = {"aaaa", "aaaa"}; 
  cout << go.numSimilarGroups(v) << endl;
  return 0;
}
