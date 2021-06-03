class Stack{
  queue<int> q1;
  queue<int> q2;
  int countSize;

public:
  Stack(){
    countSize = 0;
  }

  void push(int x){
    countSize++;

    // Tip: q2 should always be empty and from q1 we will get the answer and q1 is the one which is emptied

    q2.push(x);

    while(!q1.empty()){// copy elements to q2
      q2.push(q1.front());
      q1.pop();
    }
     swap(q1,q2);
  }

  void pop(){

    if(q1.empty()) return;
    q1.pop();

    countSize--;
  }

  int top(){
    if(q1.empty()) return -1;
    return q1.front();
  }

  int size(){
    return countSize;
  }

};

int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.pop();
  cout << s.top() << endl;
  cout << s.size() << endl;
}
