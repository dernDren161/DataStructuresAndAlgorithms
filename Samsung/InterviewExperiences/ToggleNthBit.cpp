// ith bit here starts from 1 indexing, so (i-1) is needed

int toggle(int num, int i){

  int temp = (1<<(i-1));

  return temp ^ num;                                                                            
}
