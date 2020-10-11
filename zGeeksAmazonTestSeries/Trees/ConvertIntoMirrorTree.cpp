// Problem Link: https://practice.geeksforgeeks.org/problems/mirror-tree/1/?company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1

void mirror(Node* node)
{

     if(node == NULL) return;

     if(node -> left) mirror(node -> left);

     if(node -> right) mirror(node -> right);

     swap(node -> left, node -> right);
}
