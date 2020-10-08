// Problem Link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {

   long long temp;
   long long prod = 1;

   vector<long long int > ne;

   for(long long i = 0;i<n;i++){
        temp = nums[i];
        nums[i] = 1;
        for(long long j = 0;j<n;j++){
            prod *= nums[j];
        }
        ne.push_back(prod);
        prod = 1;
        nums[i] = temp;

   }
   return ne;
}
