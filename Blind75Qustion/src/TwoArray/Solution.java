package TwoArray;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int solution(int[] prices){
        int sumMax =prices[0];
        int currMax = 0;
        for(int i = 0; i < prices.length ; i++){
            if(currMax < 0) {
                currMax = 0;
            }
            currMax = currMax + prices[i] ;
            sumMax = Math.max(sumMax, currMax);
        }
        return sumMax;
    }
}
