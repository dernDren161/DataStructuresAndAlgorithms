// Problem Link:
//https://practice.geeksforgeeks.org/problems/coin-change-minimum-number-of-coins/1/?track=amazon-dynamic-programming&batchId=192#

long long int minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
      /*
        | INT_MAX-1, INT_MAX-1, INT_MAX-1 ......
        | 0
        | 0
        | 0

    */
    int n=numberOfCoins;
                        long long t[n+1][value+1],j=0;

                        memset(t,0,sizeof(t));

                        for(int i=0;j<value+1;j++)
                        {   t[i][j]=INT_MAX-1;
                        }

                        int i=1;

                        for(int j=0;i<n+1;i++)
                            t[i][j]=0;
                        j=0;

                        // See the changes here.
                        for(i=1;j<value+1;j++)
                        {   if(j%coins[0]==0)
                                t[i][j]=j/coins[0];
                            else
                                t[i][j]=INT_MAX-1;
                        }

                        for(i=2;i<n+1;i++)
                        {   for(j=1;j<value+1;j++)
                            {   if(coins[i-1]<=j)
                                t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                                else
                                t[i][j]=t[i-1][j];
                            }
                        }

                        if(t[n][value]==INT_MAX-1)
                            return -1;
                        else
                            return t[n][value];


}
