// Intution code without proper tests being done, just dry test code

// Maximize the prices using the varied lengths given
// This question is a variation of the unbounded knapsack problem

// prices[] = {-------------}
// length[] = {1 to n} or as given in the question

// NOTE: you have to assume either prices or length array if not given in the question.

int call(int prices[], int length[], int n, int weight){

  if(n <= 0) return 0;

  if(weight >= length[n-1]){
    return max(prices[n-1] + call(prices,length,n,weight-length[n-1]), call(prices,length,n-1,weight));
  } else{
    return call(prices,length,n-1,weight);
  }
}


int main(){

  int weight = length.size();
  call(prices,length,weight,weight);
}
