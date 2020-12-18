// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/266/

// Given a Binary tree check whether it is a BST or not.

// This code does not work in leetcode, some integer overflow isssues, but ignore it

int call(Node* root, int min, int max){

    // This means that even an empty tree is a BST.
    if(root == NULL) return 1;

    if(root -> data > max || root -> data < min) return 0;

    return call(root -> left, min, root -> data - 1) && call(root -> right, root -> data + 1, max);
}

bool isBST(Node* root) {

    return call(root,INT_MIN,INT_MAX);
}
