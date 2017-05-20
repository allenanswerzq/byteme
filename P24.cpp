#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* root) {
	while (root) {
		cout << root->val << "-->";
		root = root->next;
	}
	cout << endl;
}
ListNode* swapPairs(ListNode* head) {
    ListNode *p, *q;
	p = head;
	while (p && p->next) {
		ListNode *t = p;
		ListNode *m = p->next;
		int x = 0;
		x = t->val;
		t->val = m->val;
		m->val = x;
		p = p->next->next;
	}	
	return head;
}


int main() {
	ListNode *h = new ListNode(1);
	ListNode *p = h;
	for (int i=2; i<4; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	printList(h);
	printList(swapPairs(h));
	return 0;
}
