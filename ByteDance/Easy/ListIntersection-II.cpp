// Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/

class Solution {
public:
    int getLength(ListNode* h){

        int x = 0;
        while(h){
            x++;
            h = h-> next;
        }

        return x;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int c1 = getLength(headA);
        int c2 = getLength(headB);

        ListNode* temp1 = new ListNode(NULL);
        ListNode* temp2 = new ListNode(NULL);

        if(c1>=c2){
            temp1 = headA;
            temp2 = headB;
        }else{
            temp1 = headB;
            temp2 = headA;
        }

        int x = abs(c1-c2);

        while(x--){
            temp1 = temp1 -> next;
        }

        while(temp1 && temp2){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};
