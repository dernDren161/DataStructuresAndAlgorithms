// Problem Link: https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
// Time Complexity: O(N*h*h), where N-Number of nodes and h-height of the BT

void callPath(Node* root, vector<int>&temp,int k){

    if(root == NULL) return;

    temp.push_back(root->data);
    callPath(root->left,vs);
    callPath(root->right,vs);

    int x = 0;
    for(int i=temp.size()-1;i>=0;i--){
      x = x + temp[i];
        if(x == k){
          for(int m=i;m<temp.size();m++){
            cout << temp[m] << "";
          }
            cout << endl;
        }
    }

    temp.pop_back();

}

int main(){

  vector<int> temp;

  callPath(node,temp,k);
}
