#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
  ListNode* dummy = new ListNode(-1);
  ListNode* p = dummy;
  while (p1 || p2) {
    if (p1 && p2) {
    if (p1->val <= p2->val) {
      p->next = p1; 
      p1 = p1->next;
    } else {
      p->next = p2;
      p2 = p2->next;
    }
    } else if (p1) {
    p->next = p1;
    p1 = p1->next;
    } else {
    p->next = p2;
    p2 = p2->next;
    }
    p = p->next;
  }
  return dummy->next;
  }
};

int main(int argc, char** argv) {
  return 0;
}
