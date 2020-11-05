// This code didn't pass the test case, could not figure it out though.
// Problem Link: https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1sortBysubmissions

void noSiblin(Node* node, vector<int> &vs){
        if(node == NULL) return;

    if((node -> left != NULL) && (node -> right != NULL)){
        // go with simple post order traversal
        noSiblin(node -> left,vs);
        noSiblin(node -> right,vs);
    } else if(node -> left != NULL){
        vs.push_back(node->left->data);
        noSiblin(node -> left,vs);
    } else if(node -> right != NULL){
        vs.push_back(node->right->data);
        noSiblin(node->right,vs);
    }else return;
}

vector<int> noSibling(Node* node)
{
    // post order traversal.

    vector<int> vs;
    vs.clear();

    noSiblin(node,vs);

    if(vs.empty()) vs.push_back(-1);

    return vs;
}
