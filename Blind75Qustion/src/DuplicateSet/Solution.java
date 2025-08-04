package DuplicateSet;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    public boolean solution(int[] prices){
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < prices.length ; i ++){
            if(set.contains(prices[i])){
                return true;
            }
            set.add(prices[i]);
        }
        return false;
    }
}
