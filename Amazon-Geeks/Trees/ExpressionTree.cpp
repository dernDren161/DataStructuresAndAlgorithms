// Problem Link: https://practice.geeksforgeeks.org/problems/expression-tree/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1

int evalTree(node* root) {

    if(root == NULL) return 0;

    // Assumption that only the leaf nodes have the operands
    // When the nodes are the leaf nodes
    if(!(root->left) && !(root -> right)){
        // 'stoi' helps convert the string into an integer in C++

        return stoi(root -> data); // the string is now converted into the respective int.
    }

    int x = evalTree(root -> left);
    int y = evalTree(root -> right);

    if(root -> data == "*") return x * y;
    else if(root -> data == "-") return x - y;
    else if(root -> data == "+") return x + y;
    else if(root -> data == "/") return x / y;
}
