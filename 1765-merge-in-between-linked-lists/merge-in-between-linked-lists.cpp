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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* first, *second, *cur=list1;

        int cnt = 0;

        while(cur){

            if(cnt == a-1)
            break;

            cur = cur->next;
            cnt++;

        }

        first = cur;

        while(cur){

            if(cnt == b)
            break;

            cur = cur->next;
            cnt++;

        }

        second = cur;
        // cout<<first->val<<" "<<second->val<<" "<<cur->val<<endl;
        first->next = list2;

        while(first->next)
        first = first->next;

        first->next = second->next;

        return list1;

    }
};