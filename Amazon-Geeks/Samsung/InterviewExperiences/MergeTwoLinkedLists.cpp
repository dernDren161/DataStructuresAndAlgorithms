// Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

Node* sortedMerge(Node* a, Node* b)
{
    // code here
    Node* temp = new Node(NULL);
    Node* dummy = temp;

    while(a && b){
        if(a->data <= b->data){
            temp -> next = a;
            temp = temp -> next;
            a = a-> next;
        }else if(a->data > b->data){
            temp-> next = b;
            temp = temp -> next;
            b = b-> next;
        }
    }

    if(a){
        while(a){
        temp -> next = a;
        temp = temp->next;
        a = a-> next;
        }
    }else if(b){
        while(b){
        temp -> next = b;
        temp = temp->next;
        b = b-> next;
        }
    }

    return dummy->next;
}
