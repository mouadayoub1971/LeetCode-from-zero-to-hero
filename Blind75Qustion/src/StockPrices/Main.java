package StockPrices;

public class Main {
    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 10};
        Solution sol = new Solution();
        System.out.println("The result of the Solution is : \n");
        int profit = sol.solution(prices);
        System.out.println("The result is : " + profit);

    }
}