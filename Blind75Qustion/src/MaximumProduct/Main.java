package MaximumProduct;

public class Main {
    public static void main(String[] args) {
        int[] prices = {2, 3, -2, 4};
        Solution sol = new Solution();
        System.out.println("The result of the Solution is : \n");
        int result = sol.solution(prices);
        System.out.println("The result is : " + result);

    }
}