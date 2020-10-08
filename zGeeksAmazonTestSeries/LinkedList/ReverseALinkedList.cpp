// Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

struct Node* reverseList(struct Node *head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){

        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    return head;
}
