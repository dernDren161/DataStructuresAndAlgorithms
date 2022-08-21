// Problem Link: interviewbit.com/problems/addition-without-summation/
// T.C: log(B)

int Solution::addNumbers(int A, int B) {

    // A will store the sum and B will store the carry value
    // we run a loop till the carry is 0, which seems logical

    while(B!=0){

        unsigned carry = A&B;

        A = A^B;

        B = carry << 1;
    }

    return A;
}
