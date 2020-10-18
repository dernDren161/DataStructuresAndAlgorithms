// Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// From this problem you can learn how to passs an integer from call by reference as well.

Node* call(int* pre, char preLN[], int n, int* iC){

    int t = *iC;

    if(t == n) return NULL;

    Node* cloned = new Node(pre[t]);
    (*iC)++; // this is why we used the variable 't' as clearly, t is '1' behind (*iC)

    if(preLN[t]=='N'){
        cloned -> left = call(pre,preLN,n,iC);
        cloned -> right = call(pre,preLN,n,iC);
    }

    return cloned;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i = 0;
    return call(pre,preLN,n,&i);
}
