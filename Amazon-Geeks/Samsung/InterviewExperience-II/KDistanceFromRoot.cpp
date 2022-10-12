// Problem Link: https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int> ans;

  queue<Node*> qs;
  qs.push(root);
  int level = 0;

  while(!qs.empty()){
      int x = qs.size();
      if(level==k){
          while(x--){
              Node* temp = qs.front();
              ans.push_back(temp->data);
              qs.pop();
          }

          return ans;
      }
      while(x--){
          Node* f = qs.front();
          qs.pop();
          if(f->left) qs.push(f->left);
          if(f->right) qs.push(f->right);
      }
      level++;
  }
}
