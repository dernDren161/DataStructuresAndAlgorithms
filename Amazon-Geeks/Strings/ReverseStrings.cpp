// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the string after
// reversing the alternate k characters
string revAlternateK(string s, int k, int len)
{
  for(int i=0;i<len;i++){

    if((i+k) > len) break;

    reverse(s.begin()+i,s.begin()+(i+k));
    i = i + k; // i = i + 2*k; ---> for alternate k skips.
  }

  return s;
}

// Driver code
int main()
{
	string s = "geeksforgeeks";
	int len = s.length();
	int k = 3;
	cout << revAlternateK(s, k, len);

	return 0;
}
