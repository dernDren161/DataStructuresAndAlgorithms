#include <iostream>
using namespace std;

void countOsBetween1s(string S, int N, int Q[][2])
{

	int leftBound[N];

	int rightBound[N];

	int count = 0;


	int total = 0;

	for (int i = 0; i < N; i++) {

		if (S[i] == '1') {
			count = total;
		}

		else if (S[i] == '0') {
			total++;
		}

		rightBound[i] = count;
	}

	count = 0;
	total = 0;

	for (int i = N - 1; i >= 0; i--) {


		if (S[i] == '1') {
			count = total;
		}

		else if (S[i] == '0') {
			total++;
		}

		leftBound[i] = count;
	}

	for (int q = 0; q < 2; q++) {

		int L = Q[q][0];
		int R = Q[q][1];

		count = leftBound[L] + rightBound[R] - total;

		cout << count << " ";
	}
}

// Driver Code
int main()
{

	string S = "1001010";
	int Q[][2] = { { 0, 4 }, { 0, 5 } };
	int N = S.length();
	countOsBetween1s(S, N, Q);
	return 0;
}

// This code is contributed by Potta Lokesh
