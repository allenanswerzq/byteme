#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// Perfect!!!
// Accepted :-)
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return NULL;
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    ListNode *q = head;
    while (q && q->next) {
        if (q->val != q->next->val) {
            ListNode *t = q->next;
            p->next = q;
            p = p->next;
            p->next = NULL;
            q = t;
        }else {
            while(q && q->next && q->val == q->next->val) {
                q = q->next;
            }
            q = q->next;
        }
    }
    if (q) {
        p->next = q;
    }
    return dummy->next;
}

int main(int argc, char** argv) {
    return 0;
}
