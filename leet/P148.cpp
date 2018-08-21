#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// recusive approach
// 14/15 cases passed
// TLE
ListNode* sortList(ListNode* head) {
    if (!head) return NULL;
    ListNode *last = sortList(head->next); 
    if (!last) return head;
    if (head->val < last->val) {
        head->next = last;
        return head;
    } else {
        ListNode *pre = last;
        while (pre->next && pre->next->val < head->val)
            pre = pre->next;
        head->next = pre->next;
        pre->next = head;
        return last;
    }
    // should not be reach here
    return NULL;
}

// Note: very short way to merge
ListNode* merge(ListNode *x, ListNode *y) {
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    while (x || y) {
        ListNode *t = new ListNode(INT_MAX);
        if (x && x->val < t->val)
            t = x;
        if (y && y->val < t->val)
            t = y;
        if (t == x) x = x->next;
        else        y = y->next;
        p->next = t;
        p = p->next;
    }
    return dummy->next;
}

// divie and conquer approach
// accepted
ListNode* sortList(ListNode* head) {
    if (!head) return NULL;
    if (!head->next) return head;

    ListNode *fast, *slow;
    fast = slow = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *last = slow->next;
    slow->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(last);
    return merge(l1, l2);
}

// 
int main(int argc, char** argv) {
    return 0;
}
