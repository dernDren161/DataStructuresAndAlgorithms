// Problem Link: https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

void printCorner(Node *root)
{
    if(root == NULL) return;

    queue<Node*> qs;
    qs.push(root);


    Node* testing;

    while(!qs.empty()){

        int x = qs.size();

        for(int i=0;i<x;i++){

            testing = qs.front();
            qs.pop();

            if((i==0) || (i == x-1)){
                cout << testing -> data << " ";
            }

            if((testing -> left)) qs.push(testing -> left);
            if((testing -> right)) qs.push(testing -> right);
        }
    }
}
