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
        
 ListNode* doubleIt(ListNode* head) {

     //INTUTION IS SINCE WE ARE MULTIPLYING EACH DIGIT WITH 2 SO MAX CARRY WILL ALWAYS BE 1 AS 9*2=18 SO CARRY 1.
    //  DRY RUN FOR EX - 245 TO GET GOOD UNDERSTANDING

        if (head->val > 4)
            head = new ListNode(0, head);
            
        for(ListNode* node = head; node; node = node->next) {

            node->val = (node->val * 2) % 10;

            if (node->next && node->next->val > 4)
                node->val++;
                
        }

        return head;

    }
};