/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //Node* ohead = new Node();
        Node* dummyHead = new Node(0);
        Node* cur = head, *dhead = dummyHead;

        unordered_map<Node*, Node*> mp;

        while(cur){

        Node* newNode = new Node(cur->val);
        mp[cur] = newNode;
        cur = cur->next;

        dhead->next = newNode;
        dhead = dhead->next;

        }

        cur = head;
        dhead = dummyHead->next;

        while(cur){

            Node* randomNode = cur->random ? mp[cur->random] : NULL;
            dhead->random = randomNode;

            cur = cur->next;
            dhead = dhead->next;

        }

        return dummyHead->next;

    }
};