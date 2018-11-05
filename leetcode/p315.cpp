#include <bits/stdc++.h>
using namespace std;

// TODO
// Binary index tree approach.
class Solution {
public:
  vector<int> countSmaller(vector<int>& aa) {
  vi res, bb;
  n = sz(aa);
  bb = aa;
  if (n <= 0) return res;
  bit.resize(n + 1);
  res.resize(n);
  unordered_map<int, int> mp;

  sort(all(bb));
  fori (i, 0, n) 
    mp[bb[i]] = i; 

  ford (i, n-1, -1) {
    res[i] = query(mp[aa[i]] - 1);
    update(mp[aa[i]], 1);
    pvi(bit);
  }
  return res;
  }

  void update(int ix, int inp) {
  ix += 1;
  while (ix <= n) {
    bit[ix] += inp;
    ix += ix & (-ix);
  } 
  }

  int query(int ix) {
  int res = 0;
  ix += 1;
  while (ix > 0) {
    res += bit[ix];
    ix -= ix & (-ix);
  }
  return res;
  }

  vi bit;
  int n;
};

class Solution2 {
public:
  vi countSmaller(vi& inp) {
  int n = sz(inp);
  vi tmp, res(n);
  // Using binary search to insert all element into tmp from backwards.
  fori (i, n - 1, -1) {
    auto it = lower_bound(all(tmp), inp[i]); 
    int ix = distance(it, tmp.begin());
    res[i] = ix;
    tmp.insert(it, inp[i]);
  } 
  return res;
  }
};

class Node{
public:
  int key;
  Node* left;
  Node* right;
  // The number of elements that less than `key`.
  int size;
  Node(int key, int size) 
  : key(key), size(size) {}
};

int insert(Node* &root, int key) {
  if (!root) {
  root = new Node(key, 0);
  return 0;
  }

  if (key < root->val) {
  root->size++; 
  return insert(root->left, key);
  } else {
  int aa = insert(root->right, key); 
  return aa + root->size + root->key < key ? 1 : 0;
  }
}

class Solution3 {
public:
  vi countSmaller(vi& inp) {
  int n = sz(inp);
  vi res(n);
  Node *root = nullptr;
  fori (i, n - 1, -1) {
    res[i] = insert(root, inp[i]);
  }
  return res;
  }
}

void test(vi aa) {
  Solution go;
  vi res = go.countSmaller(aa);
  pvi(res);
}

int main() {
   // test({-1, -1});
  test({5, 2, 6, 1});
  // test({7, 2, 8, 6, 5, 1});
  return 0;
}
