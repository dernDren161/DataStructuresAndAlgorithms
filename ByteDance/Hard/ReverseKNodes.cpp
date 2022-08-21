// Problem Link:https://leetcode.com/problems/reverse-nodes-in-k-group/

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

    ListNode* callKGroups(ListNode* head, int k, int c){

        if(k>c) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ne = NULL;

        int temp = 0;

        while(curr!=NULL && temp<k){
            ne = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ne;
            temp++;
        }

        if(ne!=NULL){
            head->next = callKGroups(ne,k,c-k);
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL) return NULL;

        int c = 0;
        ListNode* temp = head;

        while(temp){
            c++;
            temp = temp->next;
        }

        return callKGroups(head,k,c);
    }
};
