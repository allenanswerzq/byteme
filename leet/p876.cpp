#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode *head) {
  if (!head) return 0;
  ListNode *p = head;
  int res = 0;
  while (p) {
  p = p->next;
  ++res;
  }
  return res;
}

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
  ListNode *p, *q;
  int len = 0;
  if (!head) return null;
  if (!head->next) return head;
  len = length(head);
  p = head;
  if (len & 1) q = head->next;    
  else q = head->next->next;
  while (q) {
    p = p->next;
    q = q->next->next;
  }
  if (len % 2 == 0) return p->next;
  return p;
  }
};



int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p876-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
