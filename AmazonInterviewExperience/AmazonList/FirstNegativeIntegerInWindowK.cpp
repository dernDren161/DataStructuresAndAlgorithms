// Problem Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// T.C: O(n)
// S.C: O(k), where k is the size of the queue

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {


               long long i = 0;
               long long j = 0;

               queue<long long> qs;

               vector<long long> ans;

               while(j<N){

                    if(A[j]<0) qs.push(A[j]);

                    if(j-i+1<K) j++;
                    else if(j-i+1==K){
                        if(!qs.empty()){
                            ans.push_back(qs.front());
                        }else{
                            ans.push_back(0);
                        }

                        if(A[i]<0)qs.pop(); // NOTE: Important Point
                        i++;
                        j++;
                    }
               }

               return ans;
 }
