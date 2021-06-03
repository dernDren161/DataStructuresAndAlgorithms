// ith bit here starts from 1 indexing, so (i-1) is needed

/*
  NOTE:

  1) Toggling bits: n = n ^ (1<<i)
  2) Setting bits:  n = n | (1<<i)
  3) Clearing bits: n = n & ~(1<<i)
*/

int toggle(int num, int i){

  int temp = (1<<(i-1));

  return temp ^ num;
}
