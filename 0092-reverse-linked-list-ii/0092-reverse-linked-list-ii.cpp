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
    using ln = ListNode;

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == 1){

            ln* cur = head, *prev =  NULL;

            while(left<=right){
                
                left++;
                ln* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;

            }

            head->next = cur;
            return prev;

        }

        int cur = 1;
        ln* h = head;

        while(cur<left-1){

            h = h->next;
            cur++;

        }

        cur=left;

        ln* prev = h, *current = h->next, *hh=h;

        while(cur<=right){

            ln* nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
            cur++;

        }

        hh->next->next = current;
        hh->next = prev;

        return head;

    }
};