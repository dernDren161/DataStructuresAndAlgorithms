// Problem Link: https://leetcode.com/explore/interview/card/facebook/6/linked-list/301/



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

struct comp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
        Input: l1 = [1,2,4], l2 = [1,3,4]
        Output: [1,1,2,3,4,4]
        */

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* arr[] = {l1,l2};

        priority_queue<ListNode*,vector<ListNode*>,comp>pq;

        pq.push(arr[0]);
        pq.push(arr[1]);

        ListNode* temp = new ListNode();
        ListNode* dummy = new ListNode();
        temp = dummy;  // dummy is always right

        while(!pq.empty()){
            ListNode* cur = pq.top();
            pq.pop();

            temp -> next = cur;
            temp = temp -> next;

            if(cur -> next != NULL){
                pq.push(cur -> next);
            }

        }

        return dummy -> next;

    }
};
