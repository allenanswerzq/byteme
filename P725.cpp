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

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int len(ListNode* root) {
  int ret = 0;
  while (root) root = root->next, ret++;
  return ret;
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {
  vector<ListNode*> res;
  int l = len(root);
  for (int i=0; i<k; ++i) {
    if (root == NULL) {
      res.push_back(NULL);
      continue;
    }

    int n = l/k + (i < l%k);  // very brilliant make true no two parts have a size differing by more than 1 
    res.push_back(root);
    for (int i=0; i<n-1; ++i) root = root->next;
    ListNode *tmp = root->next;
    root->next = NULL;
    root = tmp;  
  }
  return res;
}

int main(int argc, char** argv) {
  return 0;
}

// Use deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> buf;
  vector<int> ret;
  for (auto i=0; i<nums.size(); ++i) {
    // window [i-k+1, i]  
    while (!buf.empty() && nums[i]>nums[buf.back()])
      buf.pop_back(); // buf only save the maximum value for current window
    buf.push_back(i); // put current window maximum value into buf

    if (i >= k-1) // alreay reached window size
      ret.push_back(nums[buf.front()]); // push current window maximum into ret 

    if (buf.front() == i-k+1) // pop the first element of window so we can move on to next iteration 
      buf.pop_front();  
  }
  return ret;
}