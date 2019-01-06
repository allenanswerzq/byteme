#include <bits/stdc++.h>
using namespace std;

// Given an array of numbers, verify whether 
// it is the correct preorder traversal sequence of a binary search tree.
// You may assume each number in the sequence is unique.
// Follow up:
// Could you do it using only constant space complexity?

#define vi vector<int>

class Solution {
public:
  // Use Stack
  bool verifyPreorder(vector<int>& preorder) {
    stack<int> stk;
    // Current root value
    int root = -(1 << 31); 
    for (auto p : preorder) {
      // All value in the right substree should greater than root 
      if (p < root) return false;
      // If p in right substree, find the root node of p 
      while (!stk.empty() && p > stk.top()) {
        root = stk.top();
        stk.pop();
      }
      stk.push(p);
    }
    return true;
  }

  // Divide and conquer
  bool go(vector<int>& aa, int lo, int hi, int mi, int mx) {
    if (lo >= hi) return true; 
    
    // Current root
    int root = aa[lo];  
    int i = lo + 1;

    // Find the index of first value greater than current root
    while (lo <= hi && aa[i] < root) {  
      if (aa[i] < mi || aa[i] > mx)
        return false;
      i++;
    }

    // All nodes value in the left subtree should less than current root
    // All nodes value in the right subtree should greater than root value
    return go(aa, lo + 1, i - 1, mi, root) && 
           go(aa, i, hi, root, mx);  
  }

  bool verifyPreorder(vector<int>& aa) {
    int n = aa.size();
    return go(aa, 0, n-1, INT_MIN, INT_MAX);
  }
};

void test(vi aa) {
  Solution go;
  int r = go.verifyPreorder(aa);
  output(1, r);
}

int main() {
  return 0;
}

