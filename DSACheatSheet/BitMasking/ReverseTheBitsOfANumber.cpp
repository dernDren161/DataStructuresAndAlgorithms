
int reverseBit(int n){

  int rev = 0;

  while(n){

    rev << 1;

    if(n & 1==1) rev ^= 1;

    n >> 1;
  }

  return rev;
}
