#include<bits/stdc++.h>
using namespace std;

// There are a row of n houses, 
// each house can be painted with one of the three colors: red, blue or green. 
// The cost of painting each house with a certain color is different. 
// You have to paint all the houses such that no two adjacent houses have the same color.
// The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
// For example, costs[0][0] is the cost of painting house 0 with color red; 
// costs[1][2] is the cost of painting house 1 with color green, 
// and so on... Find the minimum cost to paint all houses.
// Note:
// All costs are positive integers.

// Input contains N rows and each row have three costs with respct to three colors 
int minCost(vector<vector<int>>& costs) {
  int n = costs.size();
  for (int i=1; i<n; ++i) {
  costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
  costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
  costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
  }
  return n == 0 ? 0 : min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]) 
}

int main(int argc, char** argv) {
  return 0;
}