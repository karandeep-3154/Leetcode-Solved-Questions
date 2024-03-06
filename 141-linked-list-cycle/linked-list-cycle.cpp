/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
#define ln ListNode

    bool hasCycle(ListNode *head) {
        
        ln *slow = head, *fast = head;

        while(fast and fast->next){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            return true;

        }

        return false;

    }
};