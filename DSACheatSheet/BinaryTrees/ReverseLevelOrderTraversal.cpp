// Problem Link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*>qs;
    stack<Node*>st;
    qs.push(root);

    while(!qs.empty()){
        Node* f = qs.front();
        qs.pop();
        st.push(f);

        if(f->right)qs.push(f->right);
        if(f->left)qs.push(f->left);
    }

    vector<int>vs;

    while(!st.empty()){
        vs.push_back(st.top()->data);
        st.pop();
    }

    return vs;

}
