# Chapter 13 — 1D Dynamic Programming

> Optimal answers by combining smaller subproblems. The interview king.

## Notion

DP when:
1. **Optimal substructure** — best solution builds from best of smaller inputs
2. **Overlapping subproblems** — same subproblem solved many times (memo helps)

### Framework (always write this)

```
1. Define state: dp[i] = ???
2. Transition: how dp[i] from previous
3. Base cases
4. Order of computation
5. Answer location
```

### Top-down (memo) vs bottom-up (tabulation)

```python
# top-down
from functools import lru_cache
@lru_cache(None)
def dfs(i):
    if i == 0: return ...
    return min(dfs(i-1) + ..., dfs(i-2) + ...)

# bottom-up
dp = [0] * (n+1)
dp[0] = ...
for i in range(1, n+1):
    dp[i] = ...
```

### Pattern families

#### A. Climbing Stairs / Fibonacci

```python
# dp[i] = ways to reach i
dp[i] = dp[i-1] + dp[i-2]
```
Variants: min cost climb, decode ways.

#### B. House Robber

```python
# dp[i] = max money using houses[0..i]
dp[i] = max(dp[i-1], dp[i-2] + nums[i])
```

#### C. Longest Increasing Subsequence (LIS)

```python
# O(n²)
dp[i] = 1 + max(dp[j] for j < i if nums[j] < nums[i], default=0)
# O(n log n) patience sorting with tails binary search
```

#### D. Coin Change (unbounded knapsack 1D)

```python
dp = [inf] * (amount+1)
dp[0] = 0
for a in range(1, amount+1):
    for c in coins:
        if c <= a:
            dp[a] = min(dp[a], dp[a-c] + 1)
```

#### E. Coin Change 2 (number of combinations)

```python
# outer loop coins to avoid perm counting
dp[0] = 1
for c in coins:
    for a in range(c, amount+1):
        dp[a] += dp[a-c]
```

#### F. Word Break

```python
dp[i] = True if s[:i] can be segmented
dp[0] = True
for i in range(1, n+1):
    for j in range(i):
        if dp[j] and s[j:i] in wordset:
            dp[i] = True
            break
```

#### G. Kadane (max subarray)

```python
best = cur = nums[0]
for x in nums[1:]:
    cur = max(x, cur + x)
    best = max(best, cur)
```

#### H. Jump Game

```python
# reachability
far = 0
for i, j in enumerate(nums):
    if i > far: return False
    far = max(far, i + j)
```

#### I. Partition Equal Subset Sum

```python
# 0/1 knapsack boolean
target = total // 2
dp = [False]*(target+1)
dp[0] = True
for x in nums:
    for t in range(target, x-1, -1):  # reverse!
        dp[t] = dp[t] or dp[t-x]
```

### Space optimization

If `dp[i]` only needs last 1–2 states → O(1) variables.  
If 0/1 knapsack → 1D array updated **backwards**.

### Complexity

Time ≈ `#states × work_per_state`  
Space ≈ `#states` (or less with rolling)

---

## Associated LeetCode problems

### Easy

| # | Problem | Family |
|---|---------|--------|
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | Fib |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | Fib |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/) | Robber |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Kadane-like |
| 338 | [Counting Bits](https://leetcode.com/problems/counting-bits/) | Bits DP |
| 509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | Fib |

### Medium (core set)

| # | Problem | Family |
|---|---------|--------|
| 213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | Circular |
| 91 | [Decode Ways](https://leetcode.com/problems/decode-ways/) | Fib-like |
| 322 | [Coin Change](https://leetcode.com/problems/coin-change/) | Unbounded |
| 518 | [Coin Change II](https://leetcode.com/problems/coin-change-ii/) | Combinations |
| 139 | [Word Break](https://leetcode.com/problems/word-break/) | Break |
| 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | LIS |
| 416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | 0/1 knapsack |
| 152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | Track min/max |
| 139 | Word Break | |
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) | Greedy/DP |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | Greedy/BFS |
| 377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | Perms count |
| 343 | [Integer Break](https://leetcode.com/problems/integer-break/) | Split DP |
| 279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | Coin-like |
| 647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | Expand/DP |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | Expand/DP |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | 2D → Ch.14 |
| 494 | [Target Sum](https://leetcode.com/problems/target-sum/) | Knapsack |
| 309 | [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | State machine |
| 714 | [Best Time ... with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | State machine |

### Hard

| # | Problem |
|---|---------|
| 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) |
| 188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) |
| 472 | [Concatenated Words](https://leetcode.com/problems/concatenated-words/) |
| 140 | [Word Break II](https://leetcode.com/problems/word-break-ii/) |
| 354 | [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) | LIS 2D |
| 403 | [Frog Jump](https://leetcode.com/problems/frog-jump/) |

---

## Chapter exit criteria

- [ ] Write state + transition before any code
- [ ] House Robber / Coin Change / LIS / Word Break cold
- [ ] 0/1 knapsack reverse-loop trick
- [ ] Convert memo recursion ↔ bottom-up table
