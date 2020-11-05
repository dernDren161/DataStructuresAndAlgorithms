// Problem Link: https://practice.geeksforgeeks.org/problems/check-for-bst/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

// Given a Binary tree check whether it is a BST or not.

int call(Node* root, int min, int max){

    // This mean that even an empty tree is a BST.
    if(root == NULL) return 1;

    if(root -> data > max || root -> data < min) return 0;

    return call(root -> left, min, root -> data - 1) && call(root -> right, root -> data + 1, max);
}

bool isBST(Node* root) {

    return call(root,INT_MIN,INT_MAX);
}
