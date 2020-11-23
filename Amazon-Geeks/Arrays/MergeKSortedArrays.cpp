 // Problem Link:
 //https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// For priority queue, vector<int> is a default container and greater<> is a comparator.
// Why vector<int> while declaring a Heap?
// Because the creation of this data structure is like this only.
// Even though if we don't mention the vector<int> container, the languge understands it by default

int *mergeKArrays(int arr[][N], int k)
{
   //int answer[N*k];
   int* answer = new int[N*k];

   priority_queue<int,vector<int>,greater<int>> pq;

   for(int i=0;i<k;i++){
       for(int j=0;j<k;j++){
           pq.push(arr[i][j]);
       }
   }

   int q = 0;

   while(!pq.empty()){
       int x = pq.top();
       answer[q] = x;
       q++;
       pq.pop();
   }

   return answer;

}
