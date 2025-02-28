#include <iostream>
#include <vector>

using namespace std;

// Recursive Fibonacci (Naive)
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Memoization (Top-Down DP)
int fibMemorize(int n, vector<int> &memo) {
    if (memo[n] != -1) // Return precomputed value
        return memo[n];

    if (n == 0 || n == 1)
        return n;

    // Store computed value in memo
    memo[n] = fibMemorize(n - 1, memo) + fibMemorize(n - 2, memo);
    return memo[n];
}

// Bottom-Up DP (Tabulation)
int fibDown(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> memo(n + 1, 0);
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

// Optimized Fibonacci (O(1) Space)
int fibOptimized(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev1 = 0, prev2 = 1, curr;
    
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2; // Compute current Fibonacci number
        prev1 = prev2;        // Shift prev1 to prev2
        prev2 = curr;         // Shift prev2 to curr
    }

    return curr;
}

int main() {
    int n = 10;

    cout <<  fib(n) << endl;

    vector<int> memo(n + 1, -1);
    cout << fibMemorize(n, memo) << endl;

    cout << fibDown(n) << endl;

    cout  << fibOptimized(n) << endl;

    return 0;
}

