#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int truth;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int root){
    this -> data = root;
    this -> left = NULL;
    this -> right = NULL;
  }
};

void call(Node* root, int num){

  // I will do a post-order traversal here.

  if(root == NULL) return;

  call(root -> left, num);
  call(root -> right, num);
  if((root -> data) == num) truth = 1;
}
int main(){
  Node* root = new Node(1);
  root -> left = new Node(6);
  root -> left -> left= new Node(8);
  root -> left -> right= new Node(9);
  root -> right = new Node(3);
  root -> right -> left = new Node(11);
  root -> right -> left -> left = new Node(12);
  root -> right -> left -> left -> left= new Node(13);

  truth = 0;
  call(root,11);
  if(truth == 1) cout << "Yes it is present" << endl;
  else cout << "No it is not present" << endl;

  return 0;
}
