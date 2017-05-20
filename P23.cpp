#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *p1, *p2, *q;
	ListNode *head = new ListNode(0);
	p1 = l1, p2 = l2;
	q = head;
	while (p1 && p2) {
		if (p1->val <= p2->val){
			q->next = new ListNode(p1->val);
			q = q->next;
			p1 = p1->next;
		} else {
			q->next = new ListNode(p2->val);
			q = q->next;
			p2 = p2->next;
		}
	}
	while (p1) {
		q->next = new ListNode(p1->val);
		p1 = p1->next;
		q = q->next;
	}
	while (p2) {
		q->next = new ListNode(p2->val);
		p2 = p2->next;
		q = q->next;
	}
	return head->next;
}
// Time Limit Exceeded
ListNode* mergeKLists1(vector<ListNode*>& lists) {
	if (lists.size() <= 0) return NULL;
	ListNode *p1 = lists[0];
	ListNode *p2 = lists[1];
	ListNode *p = mergeTwoLists(p1, p2);
	for (int i=2; i<lists.size(); ++i) {
		p = mergeTwoLists(p, lists[i]);
	}
	return p;
}

void printList(ListNode* root) {
	while (root) {
		cout << root->val << "--> ";
		root = root->next;
	}
	cout << endl;
}

// Accepted
// Divide and conquer approach
ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if (n == 0) return NULL;
	if (n == 1) return lists[0];
	ListNode *ret = NULL;
	vector<ListNode*> left;
	vector<ListNode*> right;
	for (int i=0; i<n/2; ++i) left.push_back(lists[i]);
	for (int i=n/2; i<n; ++i) right.push_back(lists[i]);
	ListNode *p1 = mergeKLists(left);
	ListNode *p2 = mergeKLists(right);
	ret = mergeTwoLists(p1, p2);
	return ret;
}

int main() {
	ListNode *a = new ListNode(1);
	a->next = new ListNode(4);
	a->next->next = new ListNode(5);
	ListNode *b = new ListNode(2);
	b->next = new ListNode(6);
	b->next->next = new ListNode(8);
	ListNode *c = new ListNode(0);
	c->next = new ListNode(3);
	c->next->next = new ListNode(10);
	vector<ListNode*> list;
	list.push_back(a);
	list.push_back(b);
	list.push_back(c);
	printList(mergeKLists(list));
	return 0;
}
