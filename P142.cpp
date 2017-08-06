#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

// use extra space, but it worked
ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    unordered_map<ListNode*, bool> mp;
    ListNode *p = head;
    while (p) {
        if (mp.find(p) != mp.end()) 
            return p;
        else { 
           mp[p] = true; 
           p = p->next;
        }
    }    
    return NULL;
}

// reference: 
// https://en.wikipedia.org/wiki/Cycle_detection#Floyd.27s_Tortoise_and_Hare
// only constant sapce
ListNode *detectCycle(ListNode *head) { 
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    } 
    return NULL;
}

int main(int argc, char** argv) {
    return 0;
}
