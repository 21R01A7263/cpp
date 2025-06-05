#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//solve odd even linked list
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = odd->next->next; 
        even->next = even->next->next;
        odd = odd->next; 
        even = even->next; 
    }

    odd->next = evenHead;

    return head;
}