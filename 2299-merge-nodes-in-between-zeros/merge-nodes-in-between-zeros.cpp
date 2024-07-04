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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        int sum = 0;

        while(head){

            if(head->val == 0 and sum > 0){
                ListNode* node = new ListNode(sum);
                sum = 0;
                cur->next = node;
                cur = node;
            }

            sum += head->val;
            head = head->next;

        }

        return dummy->next;

    }
};