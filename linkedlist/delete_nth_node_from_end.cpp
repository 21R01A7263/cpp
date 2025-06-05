#include<iostream>
#include<vector>

#include<queue>

using namespace std;

// Solve using fast and slow pointers
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* deleteNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *fast = &dummy, *slow = &dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        if (fast) fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the nth node from the end
    slow->next = slow->next->next;

    return dummy.next;
}