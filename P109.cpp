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
#include <string>   // std:string std:stoi
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

TreeNode* build(ListNode* head, ListNode* tail) {
    ListNode *p = head;
    ListNode *mid = head;
    if (head == tail) return NULL;
    while (p!=tail && p->next!=tail) {
        // p is faster than mid one step
        // it means mid arrives median of List when p reach tail
        p = p->next->next;
        mid = mid->next;
    }
    TreeNode* root = new TreeNode(mid->val);
    root->left = build(head, mid);
    root->right = build(mid->next, tail);
    return root;

}

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;
    return build(head, NULL);
}

int main(int argc, char** argv) {
    return 0;
}
