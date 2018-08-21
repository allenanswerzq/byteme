#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// carefully read the statement for problems
ListNode* rotateRight(ListNode* head, int k) {
	if(!head) return NULL;
	int n =0;
	ListNode *x = head;
	while (x) {
	    x = x->next;
	    n++;
	}
	k = k % n;

	ListNode *p, *q;
	p = head;
	q = head;
	while (k-- > 0 && q) q = q->next;
	if (!q && k==0) return head;
	
	while(q->next) {
		p = p->next;
		q = q->next;
	}
	q->next = head;
	q = p->next;
	p->next = NULL;
	return q;
}

int main(int argc, char** argv) {
    return 0;
}
