// This question complements question in <BFS><Permutation>
//a functional programme.

// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1

int minSwaps(int A[], int N){
    /*Your code here */

    int A2[N];
    copy(A,A+N,A2);
    map<int,int> m;
    for(int i=0;i<N;i++){
        m[i] = A[i];
    }
    sort(A,A+N);
    int count = 0;

    for(int i =0;i<N;i++){
        if(A == A2){
            break;
        }
        if(A[i] == m[i]) continue;
        auto temp = find(A,A+N,m[i]);// this find always renders a pointer.
        swap(A[i],A[distance(A,temp)]);

        count++;
    }
    return count;
}
