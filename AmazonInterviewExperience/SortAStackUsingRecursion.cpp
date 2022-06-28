// Problem Link: https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

// T.C : O(n^2)

/*
  Let's say a stack 's' is being provided to you and you can perfrom pop(),push(),empty(),top() methods of stack
*/

void insertIntoStack(stack *s, int x){

  if(s.empty() || s.top()<x){
    s.push(x);
    return;
  }

  int temp = s.pop();
  insertIntoStack(s,x);

  s.push(temp);
}
void sortStack(stack *s){

  if(!s.empty()){
    int x = s.pop();
    sortStack(s);

    insertIntoStack(s,x);
  }
}
