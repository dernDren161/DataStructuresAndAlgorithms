// Problem Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// T.C: O(n)
// S.C: O(n)

class Solution {
public:
    Node* connect(Node* root) {

        if(root==NULL) return root;

        queue<Node*> qs;
        qs.push(root);

        while(!qs.empty()){
            int x = qs.size();

            while(x){
                Node* f = qs.front();
                qs.pop();

                if(x==1){
                    f -> next = NULL;
                }else{
                    f -> next = qs.front();
                }

                if(f->left) qs.push(f->left);
                if(f->right) qs.push(f->right);
                x--;
            }
        }

        return root;
    }
};
