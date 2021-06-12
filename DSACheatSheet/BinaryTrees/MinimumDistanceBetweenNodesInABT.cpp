// Problem Link: https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#
// TC : O(N)
// SC : O(h), here h is the height of the stack frame.

Node* callLCA(Node* root, int a, int b){

    if(root==NULL) return NULL;
    if(root->data == a) return root;
    else if(root->data==b) return root;

    Node* l = callLCA(root->left,a,b);
    Node* r = callLCA(root->right,a,b);

    if(l&&r) return root;

    if(l) return l;
    return r;
}

int findL(Node* r, int temp){

    if(r==NULL) return 0;

    if(r->data==temp){
        return 1;
    }

    int l = findL(r->left,temp);
    int ri = findL(r->right,temp);

    if(!l && !ri) return 0;

    return l+ri+1;

}

int findDist(Node* root, int a, int b) {
    // Your code here
    Node* lca = callLCA(root,a,b);
    int x = findL(lca,a);
    int y = findL(lca,b);

    return x+y-2;
}
