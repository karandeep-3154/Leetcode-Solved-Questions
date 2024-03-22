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

    pair<ListNode*, ListNode*> reverse(ListNode* head){

        if(head == NULL)
        return {head, head};

        auto data = reverse(head->next);
        ListNode* nextNode = data.first;
        
        if(nextNode == NULL)
        return {head, head};

        nextNode->next = head;
        head->next = NULL;
        return {head, data.second};

    }

    ListNode* reverseList(ListNode* head) {
        
        return reverse(head).second;

    }
};