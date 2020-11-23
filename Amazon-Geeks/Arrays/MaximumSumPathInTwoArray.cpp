// Function problem

// Problem Link:
//https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1/?track=amazon-arrays&batchId=192

// Problem Name: Maximum Sum path in two arrays

// Merge Sort Look-Alike

int max_path_sum(int A[], int B[], int l1, int l2)
{
int i = 0;
int j = 0;
int sum1 = 0;
int sum2 = 0;
int result = 0;

while(i<l1 && j<l2){
    if(A[i] < B[j]){
        sum1 += A[i++];

    }
    else if(B[j] < A[i]){
        sum2 += B[j++];

    }
    else{

        if(sum1 > sum2) result += sum1;
        else  result += sum2;

        result += A[i];
        i++;                                  // This part is important.
        j++;
         sum1 = 0;
         sum2 = 0;

    }
}

while(i<l1){
    sum1 += A[i];
    i++;
}

while(j<l2){
    sum2 += B[j];
    j++;
}
if(sum1 > sum2) result += sum1;
else  result += sum2;


return result;

}
