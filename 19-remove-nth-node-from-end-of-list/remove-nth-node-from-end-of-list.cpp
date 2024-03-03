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
    int count(ListNode* head){

        int cnt = 0;

        while(head){
            cnt++;
            head = head->next;
        }

        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL or head->next == NULL)
        return NULL;

        int cnt = count(head);
        int k = cnt-n+1, c=1;

        if(k == 1)
        return head->next;

        ListNode* cur_head = head;

        while(c<k-1){
            cur_head = cur_head->next;
            c++;
        }

        cur_head->next = cur_head->next->next;

        return head;

    }
};