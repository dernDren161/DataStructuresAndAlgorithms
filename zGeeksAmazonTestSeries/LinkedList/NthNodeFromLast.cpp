//. Problem Link: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

int pass(Node* h, int n){

    if(h == NULL) return -1;

    if(n == 1) return h -> data;

    pass(h -> next, n-1);

}

int call(Node* l, int n){

 Node* p;
 Node* curr;
 Node* ne;
 p = NULL;
 ne = NULL;
 curr = l;

 while(curr != NULL){
     ne = curr -> next;
     curr -> next = p;

     p = curr;
     curr = ne;
 }
 l = p;

 return pass( l, n);

}
int getNthFromLast(Node *head, int n)
{

     return  call(head,n);
}
