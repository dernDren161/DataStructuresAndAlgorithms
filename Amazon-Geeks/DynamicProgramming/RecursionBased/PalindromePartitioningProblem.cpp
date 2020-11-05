// This question is similar to the MCM problem in ways that this one also calculates the total number of ways or its permutations
// and then sort out the minimum value against it

int call(string& s, int i, int j){

  if(i>=j) return 0; // needs no partitioning at all so '0' number of partitions

  if(isPalindrome(s,i,j)) return 0; // if the given string is already a palindrome then the total number of partitions required is also given to be '0'

  int ans = INT_MAX;

  for(int k=i;k<=j-1;k++){
    int temp = call(s,i,k) + call(s,k+1,j) + 1 // this '1' is for the main partition between the two halves other than the recursive calls
    ans = min(ans,temp);
  }

  return ans;
}
