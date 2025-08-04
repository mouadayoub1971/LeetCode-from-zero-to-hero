package StockPrices;

import java.util.Arrays;

public class Solution {
    public int solution(int[] prices){
        int min = prices[0];
        int profit = 0;
        for(int i = 0; i< prices.length; i++ ){
            if(min > prices[i]){
                min = prices[i];
            }
            profit = Math.max(profit, prices[i] - min);
        }
        return profit;
    }
}
