// Problem Link:
//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// 1 -> 4 -> 5
// 1 -> 3 -> 4
// 2 -> 6
// will give us the result:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

/*
Complexity Analysis:

Time Complexity: O(N * log k) or O(n * k * log k), where, ‘N’ is the total number of elements among all the linked lists, ‘k’ is the total number of lists, and ‘n’ is the size of each linked list.
Insertion and deletion operation will be performed in min-heap for all N nodes.
Insertion and deletion in a min-heap require log k time.
Auxiliary Space: O(k).
The priority queue will have atmost ‘k’ number of elements at any point of time, hence the additional space required for our algorithm is O(k).
*/

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

					// important work of 'curr' here was to make a new node in every iteration
					// whereas the work of 'last' is to knit these newly formed nodes with eachother


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
