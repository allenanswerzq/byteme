#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *start = dummy;
	ListNode *end = dummy;
	while (n--) {
		end = end->next;
		if (!end) return NULL;
	}
	while (end && end->next != NULL) {
		start = start->next;
		end = end->next;
	}
	start->next = start->next->next;
	return dummy->next;
}

int main() {
	ListNode *root = new ListNode(1);
	ListNode *p = root;
	/*for(int i=2; i<=5; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	p = root;
	*/
	root = removeNthFromEnd(p, 1);
	while (root) {
		cout << root->val << " --> ";
		root = root->next;
	}
	return 0;
}
