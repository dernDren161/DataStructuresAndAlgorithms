// Problem Link: https://practice.geeksforgeeks.org/problems/occurences-of-2-as-a-digit/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage1

long long int call(long long int x){

    long long int temp = 0;

    while(x){

        if(x % 10 == 2) temp++;

        x /= 10;
    }

    return temp;
}

long long int numberOf2sinRange(long long int number)
{

    long long int c = 0;

    for(long long int i=0;i<=number;i++){

        c += call(i);
    }
    
    return c;
}
