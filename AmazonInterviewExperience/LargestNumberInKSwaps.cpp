// Problem Link: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
// NOTE: Notice in this question 'c' is not passed by call by reference
// Because we here do backtracking which might return to the previous state
// and while it backtracks to its previous state we would need to know its state
// hence the state is simply preserved

/*
  Permutation type ques: For normal permutation: n!/(n-r)!
  here, T.C: O(n!/(n-k)!), where n is the size of the string and k is the number of swaps.
*/

void call(string s, string& maxi, int c, int n){

  if(c==n) return;

  char temp = s[c];

  for(int i=c+1;i<n;i++){
    if(s[i]>temp) temp = s[i];
  }

  if(s[c]!=temp) k--;

  for(int i=c;i<n;i++){
    if(s[i]==temp){

      swap(s[i],s[c]);
      if(to_string(s) > to_string(maxi)) maxi = s;
      call(s,maxi,c+1,n);

      // Backtracking
      swap(s[i],s[c]);
    }
  }
}
int main(){

  string str;
  cin >> str;

  string maxi = str;

  call(str,maxi,0,str.size());

  cout << maxi;
}
