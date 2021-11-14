
int reverseBit(int n){

  int rev = 0;

  while(n){

    rev << 1;

    if(n & 1==1) rev ^= 1;

    n >> 1;
  }

  return rev;
}

// Count the number of set bits

int call(int n){
  int c = 0;

  while(n){
    n = n & (n-1);
    c++;
  }

  return c;
}
