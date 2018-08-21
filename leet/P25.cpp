#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode *h) {
	while (h) {
		cout << h->val;
		h = h->next;
		if (h) cout << "-->";
	}
	cout << endl;
}

ListNode* reverse(ListNode *head, int k) {
	if (!head || k<=0) return NULL;
	ListNode *p = head;
	while (p && k>0) {
		p=p->next;
		k--;
	}
	if (k > 0) return head;

	ListNode *prev = p, *curr = head;	
	while (curr != p) {
		ListNode *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}	

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k <= 0) return head;
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *p = dummy;
	while (p) {
		p->next = reverse(p->next, k);
		for (int i=0; p && i<k; ++i) {
			p = p->next;
		}
	}
	return dummy->next;
}

int main(int argc, char **argv) {
	ListNode *h = new ListNode(1);
	ListNode *p = h;
	for (int i=2; i<6; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	int n = 2;
	if (argc > 1) 
	   n = atoi(argv[1]);	
	printList(h);
	//printList(reverse(h, 6));
	printList(reverseKGroup(h, n));
	return 0;
}
