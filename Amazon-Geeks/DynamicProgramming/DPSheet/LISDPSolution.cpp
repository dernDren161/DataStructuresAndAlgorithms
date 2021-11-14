// Problem Link: https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

/*
NOTE: The recursive idea here is that

lis[i] = max(lis[i],1+lis[k]), when k<i and a[i]>a[k]
and k runs from 0 to i-1
*/

int lis(int arr[], int n)
{
	int lis[n];

	lis[0] = 1;


	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}


	return *max_element(lis, lis + n);
}
