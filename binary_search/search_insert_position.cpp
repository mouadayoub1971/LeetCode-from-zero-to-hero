class Solution {
public:
   int searchInsert(vector<int>& nums, int target) {
       int left = 0;
       int right = nums.size() - 1;
       return iterative(nums, target, left, right);
   }
private:
   int iterative(vector<int>& nums, int target, int left, int right) {
       if (left > right) {
           return left;
       }
       
       int mid = left + (right - left) / 2;
       
       if (nums[mid] == target) {
           return mid;
       }
       
       if (nums[mid] < target) {
           return iterative(nums, target, mid + 1, right);
       } 
       else {
           return iterative(nums, target, left, mid - 1);
       }
   }
};
