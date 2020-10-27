#include <stdio.h>

// Function to search an element x in nearly sorted array A
int searchElement(int A[], int n, int x)
{
	// search space is A[low..high]
	int low = 0, high = n - 1;

	// run till search space is exhausted
	while (low <= high)
	{
		// find middle index mid and compare A[mid - 1], A[mid]
		// and A[mid + 1] with the target number
		int mid = (low + high) / 2;

		// return mid if middle element is equal to target number
		if (A[mid] == x)
			return mid;

		// return mid-1 if A[mid - 1] is equal to target number
		else if (mid - 1 >= low && A[mid - 1] == x)
			return mid - 1;

		// return mid+1 if A[mid + 1] is equal to target number
		else if (mid + 1 <= high && A[mid + 1] == x)
			return mid + 1;

		// if middle element is less than the target number,
		// reduce search space to right subarray A[mid+2..high]
		else if (x > A[mid])
			low = mid + 2;

		// if middle element is greater than the target number, reduce
		// search space to right subarray A[low..mid-2]
		else
			high = mid - 2 ;
	}

	// invalid input or number not present in the array
	return -1;
}

int main(void)
{
	int A[] = { 2, 1, 3, 5, 4, 7, 6, 8, 9 };
	int target = 5;

	int n = sizeof(A) / sizeof(A[0]);
	int index = searchElement(A, n, target);

	if (index != -1)
		printf("Element %d found at index %d", target, index);
	else
		printf("Element not found in the array");

	return 0;
}
