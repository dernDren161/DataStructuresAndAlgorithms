//Problem Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1
//Convert a Binary tree to a Circular Doubly Linked List

//Here
//prev -> points to the predecessor of the inorder traversal root. That is the corresponding inorder root of the current node i.e 'root'
// root -> is the current node, this advances as the node traversal progresses
// head -> is set to the first node of the CDLL, its value is set once but it's left value changes with each increasing iteration

void call(Node* root, Node*& prev, Node*& head){

    if(root == NULL) return;
    // inorder traversal progression
    call(root->left,prev,head);


    root -> left = prev;
    if(prev){
        prev -> right = root;
    }else{
        head = root; // the head is only assigned once.
    }

    Node* ri = root -> right;

    // Now we have to make the list created till now Circular
    head -> left = root;
    root -> right = head;

    prev = root;

    call(ri,prev,head);


}

Node *bTreeToCList(Node *root)
{
    Node* prev = NULL;
    Node* head = NULL;
    call(root,prev,head);
    return head;
}
