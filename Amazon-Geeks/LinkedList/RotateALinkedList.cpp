// Problem Link:
//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

Node* call(Node** head, int k){

    Node* temp;
    temp = *head;

    while((*head) -> next != NULL){
        (*head) = (*head) -> next;
    }

    (*head) -> next = temp;

    for(int i=0;i<k-1;i++){
        temp = temp -> next;
    }

    Node* t = temp -> next;
    temp -> next = NULL;
    return t;
}
Node* rotate(Node* head, int k)
{
   return call(&head,k);
}
