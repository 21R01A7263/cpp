#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//solve using fast and slow pointers
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;

    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;        
        fast = fast->next->next;  

        if (slow == fast) {         
            return true;
        }
    }

    return false;
}