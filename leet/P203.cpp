#include <cstdio>  
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
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// Accepted
ListNode* removeElements(ListNode* head, int val) {
  ListNode *dummy = new ListNode(0);  
  ListNode *p = dummy;
  ListNode *q = head;
  while (q) {
    if (q->val != val) {
      p->next = q;
      p = p->next;
      q = q->next;
      p->next = nullptr;
    } else q=q->next;
  }
  return dummy->next;
}

int main(int argc, char** argv) {
    return 0;
}
