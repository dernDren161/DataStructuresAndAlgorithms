#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// Remember - only the left tree node's rightmost node needs to have a bridge.
// Morris Traversal
// Time complexity - O(n)
// Auxullary space - O(1)

// rather than Inorder's (recursion)
// Time complexity - O(n)
// Space complexity - O(n)

// i.e huge save in the memory management using the Morris traversal.


// conclusion.
// Morris' time complexity is almost/near to double that of inorder but
// size here is king as Morris' auxillary Space complexity is O(1)
// So trade-offs exist


// !!!! cur is initialized thrice, first Right, then Left and then finally Right (Right -> Left -> Right)

class Node{
public:
  int data;
  Node* left = NULL;
  Node* right = NULL;

  Node(int data){
    this -> data = data;
    this -> left = NULL;
    this -> right = NULL;
  }
};

void morrisInorder(Node* root){
  if (root == NULL) return;

  Node* predes;
  Node* cur;
  cur = root;
  while(cur != NULL){

    if(cur -> left == NULL){ // On reaching the Leftmost node.
      cout <<  cur -> data << " ";
      cur = cur -> right;
    }
    else{
      predes = cur -> left;
      while(predes -> right != NULL && (predes -> right != cur)) // to reach the Rightmost node.
        predes = predes -> right;

        if(predes -> right == NULL){
          predes -> right = cur;  // Bridge formation
          cur = cur -> left;   // After forming the bridge, shift the "cur" node itself.
        }
        else{ // this is breaking the bridge
          // also this means when (preceds -> right == cur)
          predes -> right = NULL;
          cout << cur -> data << " ";
          cur = cur -> right;
        }
    }
  }
}

int main(){
  Node* root = new Node(4);
  root -> left = new Node(2);
  root -> left -> left = new Node(1);
  root -> left -> right = new Node(3);
  root -> right = new Node(5);

  morrisInorder(root);
}
