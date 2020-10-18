struct compare {
	bool operator()(
		 Node* a,  Node* b)
	{
		return a->data > b->data;
	}
};

Node * mergeKLists(Node *arr[], int N)
{
       priority_queue<Node*,vector<Node*>,compare> qs;

       for(int i=0;i<N;i++){
           if(arr[i] != NULL) qs.push(arr[i]);
       }

       Node* dummy = new Node(0);
       Node* last = dummy;

       while(!qs.empty()){
           Node* curr = qs.top();
           qs.pop();

           last -> next = curr;
           last = last -> next;

           if(curr->next != NULL){
               qs.push(curr -> next);
           }
       }

       return dummy -> next;
}
