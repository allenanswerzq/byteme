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

ListNode* reverse(ListNode* head) {
  if (!head) return NULL;
  ListNode*pre=NULL, *nxt=NULL;
  while (head) {
    nxt = head->next;
    head->next = pre;
    pre = head;
    head = nxt;
  }  
  return pre; 
}

bool isPalindrome(ListNode* head) {
  if (!head || !head->next) return true;
  ListNode* slow=head;
  ListNode* fast=head;
  ListNode* h = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = reverse(slow->next);
  slow = slow->next;
  while (slow) {
    if (h->val != slow->val)
      return false;
    h = h->next;
    slow = slow->next;
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
