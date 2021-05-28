// Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {

    // Key-current node, Value-parent node
    unordered_map<TreeNode*, TreeNode*> m;

    void callToPopulate(TreeNode* root, TreeNode* parent){

        if(root == NULL) return;

        m[root] = parent;
        callToPopulate(root->left,root);
        callToPopulate(root->right,root);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(root==NULL) return {};

        callToPopulate(root,NULL);

        // Run a Simple BFS

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*>s;
        s.insert(target);

        while(k--){
            int x = q.size();

            for(int i=0;i<x;i++){

                TreeNode* f = q.front();
                q.pop();

                if(f->left && s.find(f->left)==s.end()){
                    q.push(f->left);
                    s.insert(f->left);
                }

                if(f->right && s.find(f->right)==s.end()){
                    q.push(f->right);
                    s.insert(f->right);
                }

                if(m[f]!=NULL && s.find(m[f])==s.end()){
                    q.push(m[f]);
                    s.insert(m[f]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
