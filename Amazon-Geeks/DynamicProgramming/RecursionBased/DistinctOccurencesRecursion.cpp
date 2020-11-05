/*
    S -> "banana"    ----> i = n-1 } i.e the last element
    T -> "ban"       ----> j = m-1 } ||
*/

int num(string S, string T, int i, int j){

  if(i<0 || j<0 || i<j) return 0;

  if(S[i]==T[j]){
    if(j==0) return num(S,T,i-1,j)+1; // This is actually the base case.

    else{
      return num(S,T,i-1,j) + num(S,T,i-1,j-1); // 2 cases: not selected and selected
    }
  }

  return num(S,T,i-1,j);
}
