class Solution {
public:

    int count(ListNode* head){

        int cnt = 0;
        while(head){

            head = head->next;
            cnt++;

        }

        return cnt;

    }

    ListNode* reverse(ListNode* head){

        ListNode* prev = NULL;

        while(head){

            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;

        }

        return prev;

    }

    void reorderList(ListNode* head) {
        
        int cnt = count(head);

        ListNode* rHead = head;

        if(cnt%2){

            int k=1;
            ListNode* cur = head, *prev = NULL;
            while(k<=((cnt/2)+1)){

                prev = cur;
                cur = cur->next;
                k++;

            }

            rHead = reverse(cur);
            prev->next = NULL;

        }

        else {

            int k=1;
            ListNode* cur = head, *prev = NULL;
            while(k <= cnt/2){

                prev = cur;
                cur = cur->next;
                k++;

            }

            rHead = reverse(cur);
            prev->next = NULL;

        }

        // while(head){
        //     cout<<"head val "<<head->val<<"  ";
        //     head = head->next;
        // }while(rHead){
        //     cout<<"rhead val "<<rHead->val<<"  ";
        //     rHead = rHead->next;
        // }

        while(head and rHead){

            ListNode* next = rHead;
            if(rHead->next)
            rHead = rHead->next;
            else
            rHead = NULL;
            next->next = head->next;
            head->next = next;
            head = head->next->next;

        }

    }
};