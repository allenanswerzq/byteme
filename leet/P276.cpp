#include <cstdio>
#include <stdio.h> // for using printf
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
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;
// There is a fence with n posts, each post can be painted with one of the k colors. 
// You have to paint all the posts such that no more than two adjacent fence posts 
// have the same color. Return the total number of ways you can paint the fence.
int numWays(int n, int k) {
    if(n == 0) return 0;
    else if(n == 1) return k;
    int diffColorCounts = k*(k-1);
    int sameColorCounts = k;
    for(int i=2; i<n; i++) {
        int temp = diffColorCounts;
        diffColorCounts = (diffColorCounts + sameColorCounts) * (k-1);  // if last two posts have different colors
        // then for each color picked in the last second post, there will be k-1 choices for the last one
        // And total choices for the last one is (all the ways for the last second one) * k-1
        sameColorCounts = temp;
    }
    return diffColorCounts + sameColorCounts;
}