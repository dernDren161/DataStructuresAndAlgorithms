// Problem Link:
//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// 1 -> 4 -> 5
// 1 -> 3 -> 4
// 2 -> 6
// will give us the result:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

// k ---- number of lists
// N ---- total number of elemets in the final list
// At max only k elements lie in the priority_queue
// Sorting time is: k * log k for one instance, which is with most of the merge and heap sorting algorithms
// for total : O(N*k log k) --- which is its time complexity
// space complexity: O(k), at max only k elements lie inside the priority_queue

// To create the min-heap the 'compare' class is used as is
// (    ) --  a queue
// ( y, x) -- where x is the top element
// so obviously: y should be greater than x.


// Important information:   5 -> 6 -> 7
//                          4 -> 5 -> 6
//													1 -> 2 -> 3
// The output would be:     1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 6 -> 7

// Conclusion: No matter the order of the linked lists, Just individuals lists should be sorted
// If the individual elements in the list are sorted then that is the only requiring codition of this question
// Instead if the list order are jumbled w.r.t eachother then that really does not matter at all.
// This is an important condideration to be taken into account.

struct compare {
	bool operator()( // operator overloading
		struct Node* a, struct Node* b)
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
