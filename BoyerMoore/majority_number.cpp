class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         int candidat = 0;
         int count = 0;
         for(int num : nums){
             if(count == 0){
                 candidat = num
             }
             count += (num == candidat) ? 1:-1;
         }
 
         count = 0;
         for(int num: nums) {
             if(num == candidat){
                 count ++;
             }
         }
 
         return (count > nums.size() /2) ? condidat : -1;
     }
 };