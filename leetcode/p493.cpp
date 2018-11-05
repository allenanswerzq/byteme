#include <bits/stdc++.h>
using namespace std;

// Binary search tree.
// TLE.
class Node {
public:
  Node(ll inp, ll ge) : val(inp), ge(ge), left(null), right(null) {}

  ll val;
  // The number of nodes that are greater than me in the subtree.
  ll ge;
  Node *left;
  Node *right;
};

Node* insert(Node *root, ll inp) {
  if (!root) return new Node(inp, 1);
  if (inp == root->val) ++root->ge;
  else if (inp > root->val) {
    root->right = insert(root->right, inp);
    ++root->ge;
  } else root->left = insert(root->left, inp);
  return root;
}

int search(Node *root, ll inp) {
  if (!root) return 0;
  if (inp == root->val) return root->ge;
  else if (inp < root->val) return root->ge + search(root->left, inp);
  else if (inp > root->val) return search(root->right, inp);
  else return search(root->left, inp);
}

int reversePairsBST(vi aa) {
  int res, n;
  Node *bst = nullptr;
  res = 0; n = sz(aa);
  fori (i, 0, n) {
    ll inp = 2ll * aa[i] + 1;
    res += search(bst, inp);
    bst = insert(bst, aa[i]);
  }
  return res;
}

// Binary index tree.
const int N = 50010;
int bit[N];
void update(int idx, int inp) {
  idx += 1;
  while (idx > 0) {
    bit[idx] += inp;
    idx -= idx & -idx;
  }
}

int query(int idx, int n) {
  int res;
  res = 0; idx += 1;
  while (idx < n) {
    res += bit[idx];
    idx += idx & -idx;
  }
  return res;
}

int reversePairsBIT(vi aa) {
  int n, res;
  n = sz(aa);
  mst(bit, 0);
  vi bb(aa);
  sort(all(bb));

  // pvi(aa);
  // pvi(bb);

  res = 0;
  fori (i, 0, n) {
    ll inp = 2ll * aa[i] + 1;
    int ix = lower_bound(all(bb), inp) - bb.begin();
    res += query(ix, n);
    ix = lower_bound(all(bb), aa[i]) - bb.begin();
    update(ix, 1);
    // par(bit, n+1);
  }
  return res;
}

void merge(vi& aa, int lo, int mid, int hi){
  vi bb(sz(aa), 0);
  fori (i, lo, hi+1) bb[i] = aa[i];

  int p1 = lo;
  int p2 = mid + 1;
  int k = lo;

  while (p1 <= mid || p2 <= hi){
    if (p1 > mid || (p2 <= hi && bb[p1] >= bb[p2]) ) {
      aa[k++] = bb[p2++];
    } else {
      aa[k++] = bb[p1++];
    }
  }

}

// Merge sort.
int reversePairsMergeSort(vi aa, int lo, int hi) {
  if (lo >= hi) return 0;
  int mid = lo + (hi - lo) / 2;
  int res = 0;
  res += reversePairsMergeSort(aa, lo, mid);
  res += reversePairsMergeSort(aa, mid + 1, hi);
  int j = mid + 1;
  fori (i, lo, mid+1) {
    while (j <= hi && aa[i] > 2ll * aa[j]) ++j;
    res += j - (mid + 1);
  }
  merge(aa, lo, mid, hi);
  return res;
}

// TODO
class Solution {
public:
  int reversePairs(vector<int>& aa) {
    // return reversePairsBST(aa);
    // return reversePairsBIT(aa);
    return reversePairsMergeSort(aa, 0, sz(aa) - 1);
  }
};

int test(vi aa) {
  Solution go;
  int r = go.reversePairs(aa);
  output(r);
  return r;
}

int main() {
  test({1, 3, 2, 3, 1});
  test({2, 4, 3, 5, 1});
  return 0;
}
