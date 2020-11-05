// Just a pseudocode

int call(int n, int x, int y, int z){

  if(n == 0) return 0;

  int temp = max(call(n,n-x,y,z),call(n,x,n-y,z));

  return 1 + max(temp, call(n,x,y,n-z));
}
