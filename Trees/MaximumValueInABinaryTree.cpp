#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

  int findMaxi(Node* n){

    if(n == NULL){
      return INT_MIN;
    }
    int r = n->data;
    int a = findMaxi(n->left);
    int b = findMaxi(n->right);
    if(a>b) r = a;
    if(b>a) r = b;
    return r;
  }

int main(){
  Node *n = new Node(1);
  n->left = new Node(2);            // used the same instantiation multiple times. Beauty of OOP
  n->left->right = new Node(6);
  n->left->left = new Node(0);
  n->right = new Node(7);
  n->right->left = new Node(4);
  n->right->right = new Node(55);

  cout << "The maximum node in the Binary tree is " << endl;
  cout << findMaxi(n) << endl;
  return 0;
}
