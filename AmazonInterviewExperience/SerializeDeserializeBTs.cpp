// Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string.
    string s = "";

    void callPreorder(TreeNode* root){

        if(root==NULL){
            s += "X ";
            return;
        }
        s += to_string(root->val);
        s += " ";

        callPreorder(root->left);
        callPreorder(root->right);
        return;
    }
    string serialize(TreeNode* root) {
        callPreorder(root);
        s.pop_back();

        return s;
    }

    // Decodes your encoded data to tree.

    TreeNode* callToDecode(stringstream& data){

        string temp;

        data >> temp;

        if(temp=="X") return NULL; // NOTE: NOTICE that didn't do "X "

        TreeNode* x = new TreeNode(stoi(temp));

        x->left = callToDecode(data);
        x->right = callToDecode(data);
        return x;
    }
    TreeNode* deserialize(string data) {

        if(data.size()==0) return NULL;
        stringstream temp(data);

        return callToDecode(temp);
    }
};
