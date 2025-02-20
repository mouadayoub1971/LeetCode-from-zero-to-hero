class Solution {
 public:
     int minSubArrayLen(int target, vector<int>& nums) {
         int l = 0;
         int res = nums.size() + 1;
         long long sum = 0;
         for ( int r = 0; r< nums.size() ; ++r){
             sum += nums[r];
             while( sum >= target) {
                 res  = min(res , r - l +1 );
                 sum -= nums[l];
                 l++;
             }
 
             
         }
         return res == nums.size() + 1 ? 0 : res;
     }
 };