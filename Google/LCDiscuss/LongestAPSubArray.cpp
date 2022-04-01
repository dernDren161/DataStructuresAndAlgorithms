// C++ Program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the length
// of longest subarray forming an AP
int getMaxLength(int arr[], int N)
{

	if(N==1)
	return 1;


	int res = 2;

	int dist = 2;

	int curradj = (arr[1] - arr[0]);

	int prevadj = (arr[1] - arr[0]);
	for (int i = 2; i < N; i++) {
		curradj = arr[i] - arr[i - 1];

		// If the common differences
		// are found to be equal
		if (curradj == prevadj) {

			// Continue the previous subarray
			dist++;
		}


		else {
			prevadj = curradj;

			res = max(res, dist);
			dist = 2;
		}
	}

	// Update the length to
	// store maximum length
	res = max(res, dist);

	return res;
}
