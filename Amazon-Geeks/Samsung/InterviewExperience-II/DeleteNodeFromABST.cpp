// Problem Link: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung

// Function to delete a node from BST.
Node* findSuccessor(Node* r){

    Node* a = r;

    while(a && a->left){
        a = a->left;
    }

    return a;
}

Node* call(Node* r, int x){

    if(r==NULL) return r;

    if(r->data > x){
        r->left = call(r->left,x);
    }else if(r->data < x){
        r->right = call(r->right,x);
    }else{ // if the key is found
        if(r->left==NULL && r->right==NULL){
            return NULL;
        }

        if(r->right==NULL){
            Node* tr = r->left;
            free(r);
            return tr;
        }
        if(r->left==NULL){
            Node* tl = r->right;
            free(r);
            return tl;
        }
        // if both the left and right nodes are available then just go ahead and find the 'inorder succesor' of the key node
        Node* inorderSuccessor = findSuccessor(r->right);
        r->data = inorderSuccessor->data;

        r->right = call(r->right,inorderSuccessor->data);
    }
    return r;
}
Node *deleteNode(Node *root, int X) {
    // your code goes here
    return call(root,X);
}
