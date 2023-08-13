/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
        
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
        
    head = reverse(head);

    ListNode* current = head;
    ListNode* newHead = nullptr;
    ListNode* newTail = nullptr;
    int carry = 0;

    while (current != nullptr) {
        int newValue = current->val * 2 + carry;
        carry = newValue / 10;
        newValue %= 10;

        if (newHead == nullptr) {
            newHead = new ListNode(newValue);
            newTail = newHead;
        } else {
            newTail->next = new ListNode(newValue);
            newTail = newTail->next;
        }

        current = current->next;
    }

    while (carry > 0) {
        newTail->next = new ListNode(carry % 10);
        carry /= 10;
        newTail = newTail->next;
    }

    return reverse(newHead);
    }
};