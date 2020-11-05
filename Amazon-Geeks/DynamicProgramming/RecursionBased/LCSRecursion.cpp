
int call(string& x, string& y, int m, int n){

    if(m==0 || n==0 ) return 0;

    if(x[m-1] == y[n-1]) return 1+call(x,y,m-1,n-1);

    else{
      return max(call(x,y,m,n-1), call(x,y,m-1,n));
    }
}

int main(){
    return call(x,y,m,n);
}
