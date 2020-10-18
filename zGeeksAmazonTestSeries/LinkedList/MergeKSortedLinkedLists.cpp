// Problem Link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// 1 -> 4 -> 5
// 1 -> 3 -> 4
// 2 -> 6
// will give us the result:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

// k ---- number of lists
// N ---- total number of elemets in the final list
// At max only k elements lie in the priority_queue
// Sorting time is: log k for one instance
// for total : O(N log k) --- which is its time complexity
// space complexity: O(k), at max only k elements lie inside the priority_queue

// To create the min-heap the 'compare' class is used as is
// (    ) --  a queue
// ( y, x) -- where x is the top element
// so obviously: y should be greater than x.

struct compare {
	bool operator()(
		struct Node* a, struct Node* b)
	{
		return a->data > b->data;
	}
};

Node * mergeKLists(Node *arr[], int N)
{
       priority_queue<Node*,vector<Node*>,compare> qs;
compare
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
