// Problem Difficulty: Medium (4)

// Problem Link:
//https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/?track=amazon-arrays&batchId=192
int max_sum(int A[],int N)
{
    int sum = 0;
    for(int i=0;i<N;i++){
        sum += A[i];
    }

    int iSum = 0;

    for(int i = 0;i<N;i++){
        iSum += (i * A[i]);
    }
    int y = iSum;
    int temp;


    for(int i = 1; i<N;i++){
        temp = (iSum - sum) + A[i-1] + (A[i-1] * (N-1));
        iSum = temp;
        if(temp > y) y = temp;

    }

    return y;
}
