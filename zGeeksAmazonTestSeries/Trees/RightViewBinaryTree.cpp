// Problem Link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/?track=amazon-trees&batchId=192

void call(Node* root){
    if(root == NULL) return;

    queue<Node*> qs;
    qs.push(root);
    qs.push(NULL);

    Node* cur;
    Node* temp;
    while(qs.size() > 1){
        cur = qs.front();

        qs.pop();


        if(cur == NULL){
            qs.push(NULL);
            cout << temp -> data << " ";
        }

        else{
             if(cur -> left){
             qs.push(cur -> left);
             }

             if(cur -> right){
             qs.push(cur -> right);
             }
        }

        temp = cur;
        // cout << cur -> data;

    }
    cout << temp -> data << " ";
}

void rightView(Node *root)
{
   call(root);
}
