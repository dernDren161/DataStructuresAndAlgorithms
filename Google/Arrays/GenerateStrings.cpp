// Discuss Link: https://leetcode.com/discuss/interview-question/1675763/Google-L3-or-Phone-Interview-or-USA

string generatePair(int n, int pairs) {

       // At max we can have n*(n-(n/2)) pairs of subsequence 01
       // Considering the maximum case is at half of places we have 0 and the rest half filled with 1

       // Maximum is : (n/2)*(n+1)/2
       
       if(pairs > (n*(n - (n/2))))
       {
           return "";
       }

       string output(n, '1');

       int result = 0;
       int zeroes = 0;

       for(int i = 0; i < n; i++)
       {
           // If I place a zero at this position then the outcome would be
           // newResult = result - (zeroes) + n-i-1;
           // we need to subtract those cases when we assumed 1 at this position along with the previous zeroes and need to add n-i-1 new pairs

           int newResult = result - zeroes + n-i-1;

           // Now we need to check whether it is optimal to place 0 here or not
           if(newResult <= pairs)
           {
               output[i] = '0';
               result = newResult;
               zeroes++;
           }

           // If we get our answer we can break else it will keep on replacing 1 with 0 and hence decreasing our total pairs count
           if(newResult == pairs)
           {
               break;
           }
       }

       return output;
   }
