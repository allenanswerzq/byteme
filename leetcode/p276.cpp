#include<bits/stdc++.h>
using namespace std;

// There is a fence with n posts, each post can be painted with one of the k colors. 
// You have to paint all the posts such that no more than two adjacent fence posts 
// have the same color. Return the total number of ways you can paint the fence.

class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0) return 0;
    else if (n == 1) return k;

    int diff = k * (k-1);
    int same = k;

    for (int i = 2; i < n; i++) {
      int temp = diff;
      // If last two posts have different colors
      diff = (diff + same) * (k - 1);  
      // then for each color picked in the last second post, there will be k-1 choices for the last one
      // And total choices for the last one is (all the ways for the last second one) * k-1
      same = temp;
    }

    return diff + same;
  }
};
