#include<bits/stdc++.h>
using namespace std;

class Solution{

  struct Node{
    int val;
    struct Node* next;
    Node(int val){
      this->val = val;
      next = NULL;
    }
  }

  void call2(Node* head){
    if(head == NULL) return;

    Node* slow = head;
    Node* fast = head;
    fast = fast -> next;

    while(fast && fast->next){
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    // slow is the middle element
    Node* h1;
    Node* h2;
    h2 = slow -> next;
    slow -> next = NULL;
    // reverse the second
    Node* curr = h2;
    Node* prev = NULL;
    Node* next = NULL;

    // reverse
    while(curr != NULL){
      next = curr-> next;
      curr -> next = prev;
      prev = curr;
      curr = next;
    }
    h2 = prev;

    Node* temp = new Node();
    Node* dummy = new Node();

    dummy = temp;

    while(h1 || h2){
      if(h1!=NULL){
        temp -> next = h1;
        temp = temp -> next;
        h1 = h1 -> next;
      }

      if(h1 != NULL){
        temp -> next = h2;
        temp = temp -> next;
        h2 = h2 -> next;
      }
    }

    return dummy -> next;
  }
  void call(Node** head, int temp){
    Node* dummy = new Node(temp);
    dummy -> next = (*head);
    head = dummy;
  }
  int main(){
    int val;
    int n;
    cin >> n;
    Node* x = new Node(-1);
    int temp;

    for(int i=0;i<n;i++){
          cin >> temp;
          call(&x,temp);
    }
    call2(a);
  }
}
