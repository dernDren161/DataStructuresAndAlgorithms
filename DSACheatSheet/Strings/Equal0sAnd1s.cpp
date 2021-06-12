// Problem Link: https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

// NOTE: The expected output has to be the maxumum number of partitions instead
int call(string s){

  int count0 = 0;
  int count1 = 0;

  int cnt = 0;

  for(int i=0;i<s.size();i++){
    if(s[i]=='0') count0++;
    else if(s[i]=='1') count1++;

    if(count0 == count1) cnt++;
  }

  if(count0 != count1) return -1;

  return cnt;
}
