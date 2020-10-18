// Problem Link: https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// This function is required to clone the random pointers as well
// Extra step that needed the use of maps which makes the question a medium type one.
Node* call2(Node* root, Node* clonedNode, map<Node*,Node*> &m){

    if(root == NULL || clonedNode == NULL) return NULL;

    clonedNode -> random = m[root->random];

    // a post order type traversal
    call2(root->left,clonedNode->left,m);
    call2(root->right,clonedNode->right,m);

    return clonedNode;
}

// This much was enough had the question told to just clone a Binary Tree
Node* call(Node* root, map<Node*,Node*> &m){

    if(root == NULL) return NULL;

    Node* clonedNode = new Node(root->data);

    m[root] = clonedNode;

    clonedNode->left = call(root->left,m);
    clonedNode->right = call(root->right,m);
    return clonedNode;
}

Node* cloneTree(Node* tree)
{
    if(tree == NULL) return NULL;

    map<Node*, Node*> m;

    Node* newNode = call(tree,m); // 'newNode' is the head pointer to node for the cloned tree.

    return call2(tree,newNode,m);

}
