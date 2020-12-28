class Solution {
public:
    int divide(int dividend, int divisor) {

        // dividend = divisor * quotient + remainder

        // when the remainder is removed, then
        // dividend >= (divisor * quotient)

        // 12/ 3 is equal to 4, or
        // 3+3+3+3 <= 12 (X4 times)
        // if, 11/3 is equal to 3, or
        // 6+3, we need to find this similar distribution similarly.


        // The time complexity here is: log(Divident)
        // Last test case not passed on Leetcode :'(
        long long int Dividend = abs((long long) dividend);
        long long int Divisor = abs((long long) divisor);
        


        long long int temp = 0;
        long long int quotient = 0;



        long long int flag = ((dividend < 0)^(divisor < 0))? -1:1;

        for(long long int i=31;i>=0;i--){

            if(Dividend >= (Divisor << i) + temp ){ // the very first time, we get the highest factor

                temp = temp + (Divisor << i);
                quotient = quotient | (1LL<<i);
            }
        }

        if(quotient == -2147483648 ) return 2147483647;

        return quotient*flag;

    }
};
