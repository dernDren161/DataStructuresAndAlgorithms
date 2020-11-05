
// Problem Link: https://practice.geeksforgeeks.org/problems/symmetric-tree/1/?track=amazon-trees&batchId=192#fullSoln

bool call(Node* l, Node* r){


    if(l == NULL && r == NULL) return true;


    // (l && r) means to say that both l and r exist.
    if(l && r && (l -> data == r -> data)){
        return (call(l -> left, r -> right) && call(l -> right, r -> left));
    }

    return false;
}

bool isSymmetric(struct Node* root)
{
    return call(root, root);
}
