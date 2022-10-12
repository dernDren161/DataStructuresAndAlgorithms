// Problem Link: https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

Node* deleteNode(Node *head,int x)
{
    int c = 1;
    Node* temp = head;
    Node* temp2;

    while(temp){
        if(c==x && temp->next == NULL){
            free(temp);
            temp2 -> next = NULL;
            return head;
        }
        if(c==x){
            Node* t1 = temp->next;
            Node* t2 = t1->next;
            temp->data = t1->data;
            temp->next = t2;
            return head;
        }
        temp2 = temp;
        temp = temp->next;
        c++;
    }
}
