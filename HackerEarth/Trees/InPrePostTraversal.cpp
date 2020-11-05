#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this-> data = data;
    this-> left = NULL;
    this-> right = NULL;
  }
};

void inOrder(Node* root){
  //LDR
  if(root == NULL) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node* root){
  // LRD
  if(root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void preOrder(Node* root){
  // dfs --- DLR
  if(root == NULL) return;

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main(){
  Node* root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(5);
  root -> right = new Node(3);

  cout << "The Preorder is: " << endl;
  preOrder(root);
  cout << endl;
  cout << "The Inorder is: " <<  endl;
  inOrder(root);
  cout << endl;
  cout << "The Postorder is: " << endl;
  postOrder(root);
  cout << endl;

  return 0;
}
