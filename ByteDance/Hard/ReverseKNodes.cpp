// Problem Link:https://leetcode.com/problems/reverse-nodes-in-k-group/

public:
ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* curr = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;

    int count = 0;

    ListNode* temp = head;
    int cnt = 0;

    // Checking if number of nodes is a multiple of k or not
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }

    // if not multiple of k then don't reverse the remaining nodes
    if(cnt < k){
        return head;
    }

    //Reverse first k nodes
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = reverseKGroup(next, k);
    }

    return prev;
}
};
