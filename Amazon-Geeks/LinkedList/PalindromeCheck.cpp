// Problem Link:
//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

bool call(Node** l, Node* r){

    if(r == NULL) return true;

    bool i = call(&*l, r-> next);
    if(!i) return false;
    bool j = ((*l) -> data == r -> data);
    (*l) = (*l) -> next;
    return j;
}

bool isPalindrome(Node *head)
{
   return call(&head,head);  // &head means here -> a pointer to another pointer
}
