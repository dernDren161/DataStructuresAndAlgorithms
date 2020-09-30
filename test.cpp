// C++ program to cover a sequence of points
// in minimum steps in a given order.
#include <bits/stdc++.h>
using namespace std;

// cell structure denoted as point
struct point {
	int x, y;
};

// function to give minimum steps to
// move from point p1 to p2
int shortestPath(point p1, point p2)
{
	// dx is total horizontal
	// distance to be covered
	int dx = abs(p1.x - p2.x);

	// dy is total vertical
	// distance to be covered
	int dy = abs(p1.y - p2.y);

	// required answer is
	// maximum of these two
	return max(dx, dy);
}

// Function to return the minimum steps
int coverPoints(point sequence[], int size)
{
	int stepCount = 0; 

	// finding steps for each
	// consecutive point in the sequence
	for (int i = 0; i < size - 1; i++) {
		stepCount += shortestPath(sequence[i],
								sequence[i + 1]);
	}

	return stepCount;
}

// Driver code
int main()
{
	// arr stores sequence of points
	// that are to be visited
	point arr[] = { { 4, 6 }, { 1, 2 }, { 4, 5 }, { 10, 12 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << coverPoints(arr, n);
}
