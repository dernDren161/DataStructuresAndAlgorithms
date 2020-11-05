// Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// Tip: if you want to access a 'vector<int>vs' as an array like vs[4] = 90;
// then be sure to make it static like arrays, as 'vector<int>vs(100)', which signifies its size.

void callInorder1(Node* root1, vector<int>& inOrder1){
    if(root1 == NULL) return;

    // going for an inorder traversal

    callInorder1(root1 -> left,inOrder1);
    inOrder1.push_back(root1 -> data);
    callInorder1(root1 -> right,inOrder1);

}
void callInorder2(Node* root2, vector<int>& inOrder2){
    if(root2 == NULL) return;

    // going for an inorder traversal

    callInorder1(root2 -> left,inOrder2);
    inOrder2.push_back(root2 -> data);
    callInorder1(root2 -> right,inOrder2);

}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int>inOrder1;
    vector<int>inOrder2;

    inOrder1.clear();
    inOrder2.clear();

    if(root1 == NULL || root2 == NULL) {
        inOrder1.push_back(-1);
        return inOrder1;
    }

   callInorder1(root1,inOrder1);
   callInorder2(root2,inOrder2);

   // We now get two sorted vectors.
   int x = inOrder1.size();
   int y = inOrder2.size();

   vector<int> theAnswer(x+y);

   int a = 0;
   int b = 0;
   int k = 0;

   while(a < x && b < y){
       if(inOrder1[a] <= inOrder2[b]){
           theAnswer[k] = inOrder1[a];
           a++;
           k++;
       }else{
           theAnswer[k] = inOrder2[b];
           b++;
           k++;
       }
   }

   while(a < x){
       theAnswer[k] = inOrder1[a];
       a++;
       k++;
   }

   while(b < y){
       theAnswer[k] = inOrder2[b];
       b++;
       k++;
   }

   return theAnswer;
}
