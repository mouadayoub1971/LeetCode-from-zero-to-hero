package DuplicateSet;

public class Main {
    public static void main(String[] args) {
        int[] prices = {1 , 4 , 8 , 10 , 5, 40};
        Solution sol = new Solution();
        System.out.println("The result of the Solution is : \n");
        boolean result = sol.solution(prices);
        System.out.println("The result is : " + result);

    }
}