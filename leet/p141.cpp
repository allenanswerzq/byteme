#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
  bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode *fast = head, *slow = head; 
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) 
        return true;
    }
    return false;
  }
};

int main(int argc, char** argv) {
  return 0;
}
