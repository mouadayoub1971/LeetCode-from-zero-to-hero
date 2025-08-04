package MaximumProduct;

import java.lang.reflect.MalformedParameterizedTypeException;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int solution(int[] nums){
        if(nums.length == 0){
            return  0;
        }
        int max = nums[0];
        int min = nums[0];
        int result = max;
        for(int i = 1; i< nums.length ; i++){
            int temp = Math.min(Math.min(nums[i], min * nums[i]), nums[i] * max);
            max = Math.max(Math.max(nums[i], min * nums[i]),nums[i] * max);
            min = temp;
            result = Math.max(result, max);
        }
        return result;
    }
}
