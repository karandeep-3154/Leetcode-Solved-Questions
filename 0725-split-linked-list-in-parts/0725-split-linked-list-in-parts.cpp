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

    using ls = ListNode;

    int size(ls* head){

        int cnt = 0;

        while(head){

            head = head->next;
            cnt++;

        }

        return cnt;

    }

    ls* breakll(ls* head, int k){

        ls* ans=head;

        if(head == NULL)
        return ans;

        while(k>1){

            head = head->next;
            k--;

        }

        ans = head->next;
        head->next = NULL;

        return ans;

    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int cnt = size(head);

        int rem = cnt%k;
        int grp = cnt/k;

        vector<ls*> ans;

        for(int i=1;i<=k;i++){

            ans.push_back(head);

            ls* newhead;

            if(rem){
                newhead = breakll(head, grp+1);
                rem--;
            }

            else
            newhead = breakll(head, grp);

            head = newhead;

        }

        return ans;

    }
};