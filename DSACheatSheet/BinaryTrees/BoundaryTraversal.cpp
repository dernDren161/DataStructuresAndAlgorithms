// Problem Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

class Solution {
public:
    vector<int> vs;

    void callLeaves(Node* r){
        if(r){
            callLeaves(r->left);
            if(r->left==NULL && r->right==NULL){
                vs.push_back(r->data);
            }
            callLeaves(r->right);
        }

    }

    void callRightBoundary(Node* r){
        if(r){
            if(r->right){
                callRightBoundary(r->right);    // NOTE: Note this important point.
                 vs.push_back(r->data);
            }else if(r->left){
                callRightBoundary(r->left);
                vs.push_back(r->data);
            }
        }

    }

    void callLeftBoundary(Node* r){

        if(r){
            if(r->left){
                vs.push_back(r->data);
                callLeftBoundary(r->left);
            }else if(r->right){
                vs.push_back(r->data);
                callLeftBoundary(r->right);
            }
        }

    }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vs.push_back(root->data);

        callLeftBoundary(root->left);
        callLeaves(root->left);
        callLeaves(root->right);
        callRightBoundary(root->right);

        return vs;
    }
};
