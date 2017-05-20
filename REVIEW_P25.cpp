#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

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

	return ret;
}	

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k <= 0) return head;

}

int main() {
	ListNode *h = new ListNode(1);
	ListNode *p = h;
	for (int i=2; i<6; ++i) {
		p->next = new ListNode(i);
		p = p->next;
	}
	printList(h);
	printList(reverseKGroup(h, 2));
	return 0;
}
