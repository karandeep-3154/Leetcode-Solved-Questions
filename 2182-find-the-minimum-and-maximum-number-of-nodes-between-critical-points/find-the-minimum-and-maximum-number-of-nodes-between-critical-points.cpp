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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int maxi = -1, mini = 1e9;

        ListNode* first = head, *prev = head, *cur = head->next, *last = head;
        int total = 0, st = 0;

        while(cur->next){

            if((cur->val > last -> val and cur->val > cur->next->val) or (cur->val < last -> val and cur->val < cur->next->val)){//cur is a critical point

                if(first == head){

                    first = cur;
                    total = 0;
                    st = 0;

                }
                
                else{

                    maxi = total;
                    mini = min(mini, st);
                    st = 0; 

                }             

            }

            total++;
            st++;
            last = cur;
            cur = cur->next;

        }

        if(maxi == -1)
        return {-1, -1};

        return {mini, maxi};

    }
};