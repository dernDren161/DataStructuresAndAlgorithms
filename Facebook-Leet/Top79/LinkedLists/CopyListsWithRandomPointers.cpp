// Problem Link: https://leetcode.com/explore/interview/card/facebook/6/linked-list/3020/
// NOTE: Hint is @OC, i.e original node(key) and cloned node(value)


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

        if(head == NULL) return NULL;

        map<Node*,Node*> m;
        // key -> original node
        // value -> the cloned node

        Node* temp = new Node(-1);
        temp = head;

        // for copying the values and creating the hash map

        while(temp){ // while(temp != NULL)
            Node* cur = new Node(temp->val);

            m[temp] = cur;
            temp = temp -> next;
        }

        temp = head;

        while(temp){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp -> next;
        }

        return m[head];
    }
};
