// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/544/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {

    void call(Node* r, Node** temp){

        // in (*temp), these brackets are extremely important

        if(r == NULL || (*temp) == NULL) return;

        // to do an inorder traversal --- LDR

        call(r -> left, &*temp);

        (*temp) -> right = r;
        r -> left = (*temp);
        (*temp) = r;

        call(r -> right, &*temp);
    }
public:
    Node* treeToDoublyList(Node* root) {

        if(root == NULL) return NULL;

        Node* temp = new Node(0);
        Node* dummy = new Node(0);
        temp = dummy;

        //Node* collect = new Node(-3);

        call(root,&temp);

        temp -> right = dummy -> right;
        dummy->right->left = temp;

        return dummy -> right;
    }
};
