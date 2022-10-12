// NOTE:Catalan number sequence
// 1,1,2,5,14,42
// Read as 0th,1st,2nd,3rd,4th.... Catalan numbers

#include<iostream>
using namespace std;

// A sequence of the catalan numbers.

// Foruma for mth catalan number is:
/*
  C(m) = E(i=0 to m-1) C(i) * C(m-i-1);
  this shows that for mth number we need the summation of all the numbers till m-1
  Hence, the inner loop is for this and the outer loop is to reach till m

*/
unsigned long int catalanDP(unsigned int n)
{

    unsigned long int catalan[n+1];


    catalan[0] = catalan[1] = 1;


    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)  // NOTE: Goes till i-1 and not i
            catalan[i] += catalan[j] * catalan[i-j-1];
    }

    // Return last entry
    return catalan[n];
}

unsigned long int countWays(unsigned long int n)
{
   // Throw error if n is odd
   if (n & 1)
   {
      cout << "Invalid";
      return 0;
   }

   // Else return n/2'th Catalan number
   return catalanDP(n/2);
}

// Driver program to test above function
int main()
{
    cout << countWays(6) << " ";
    return 0;
}
