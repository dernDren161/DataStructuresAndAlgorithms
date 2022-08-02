// Problem Link: https://practice.geeksforgeeks.org/problems/make-binary-tree/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// This code does not work but the concept is correct, just learn the concepts.

void call(TreeNode*& root, vector<int>&vs, int i){

    if(i>=vs.size()){
        root = NULL;
        return;
    }

    root = new TreeNode(vs[i]);

    call(root->left,vs,2*i+1);
    call(root->right,vs,2*i+2);
}

void convert(Node *head, TreeNode *&root) {

    vector<int>vs;
    while(head){
        vs.push_back(head->data);
        head = head -> next;
    }

    call(root,vs,0);
}
