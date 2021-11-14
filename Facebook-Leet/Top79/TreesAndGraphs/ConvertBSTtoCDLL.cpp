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
public:

    void call(Node* root,Node*& prev,Node*& head){

        if(root==NULL) return;

        call(root->left,prev,head);

        root->left = prev;

        if(prev){
            prev->right = root;
        }else{
            head = root;
        }

        Node* ri = root->right;

        head ->left = root;
        root->right = head;

        prev = root;

        call(ri,prev,head);

    }

    Node* treeToDoublyList(Node* root) {

        Node* prev = NULL;
        Node* head = NULL;

        call(root,prev,head);

        return head;
    }
};
