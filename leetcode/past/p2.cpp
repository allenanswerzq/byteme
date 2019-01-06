#include <bits/stdc++.h>
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

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int x, y, sum, carry = 0;
    struct ListNode *dummy = new ListNode(-1);
    struct ListNode *p = dummy;
    
    while (l1 || l2) {
      x = getValue(l1);
      y = getValue(l2);
      sum = x + y + carry;

      ListNode *node = new ListNode(sum % 10);
      p->next = node;
      p = p->next;
      carry = sum / 10;
    }

    if (carry > 0) {
      ListNode *node = new ListNode(carry);
      p->next = node;
      p = p->next;
    }

    return dummy->next;
  }
  
  int getValue(ListNode* &p) {
    int ret = 0;
    if (p) {
      ret = p->val;
      p = p->next;
    }
    return ret;
  }
};

int main() {
   return 0;
}
