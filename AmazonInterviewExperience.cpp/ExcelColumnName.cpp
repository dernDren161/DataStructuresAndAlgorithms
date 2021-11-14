// Problem Link: https://www.geeksforgeeks.org/find-excel-column-name-given-number/

void printString(int n){

  char str[100];
  int i = 0;
  int temp;

  while(n){
    temp = n%26;

    if(temp==0){
      str[i] = 'Z';
      i++;
      n = (n/26)-1;
    }else{
      str[i] = (temp-1) + 'A';
      i++;
      n = n/26;
    }
  }

  str[i] = '\0';

  string result = "";

  for(char c:str){
    if(isalpha(c)){
      result = c + result;
    }
  }

  return result;
}
