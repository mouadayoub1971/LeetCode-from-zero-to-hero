package RotatedArray;

public class Solution {
    public int solution(int[] nums){
        if(nums.length == 1){
            return nums[0];
        }
        int result = nums[0];
        int left = 0;
        int right = nums.length-1;
        while(left <=right){
            if(nums[left] < nums[right]){
                result = Math.min(result, nums[left]);
            }
            int mid = (right + left) / 2;
            result = Math.min(result, nums[mid]);
            if(nums[left] <= nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}
