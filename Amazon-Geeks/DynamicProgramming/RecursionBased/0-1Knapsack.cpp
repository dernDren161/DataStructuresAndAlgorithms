
// Time complexity of this recursion approach: O(2^n)
// Auxillary time complexity: O(1), as no extra array is used in the computation.

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{

	// Base Case
	if (n == 0 || W == 0)
		return 0;

	if(W >= wt[n-1]){
		return max((val[n-1]+knapSack(W-wt[n-1],wt,val,n-1)),(knapSack(W,wt,val,n-1)));
	}

	if(W < wt[n-1]){
		return knapSack(W,wt,val,n-1);
	}

}

// Driver code
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}
