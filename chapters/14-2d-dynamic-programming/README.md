# Chapter 14 — 2D Dynamic Programming

> Grids, two strings, knapsack with two dimensions. Hard Mediums live here.

## Notion

State becomes 2D (or more): `dp[i][j]`.

### Pattern A — Unique paths / grid min path

```python
# unique paths
dp[i][j] = dp[i-1][j] + dp[i][j-1]

# min path sum
dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
```

Can compress to 1D rolling row.

### Pattern B — Longest Common Subsequence (LCS)

```python
# dp[i][j] = LCS of text1[:i], text2[:j]
if text1[i-1] == text2[j-1]:
    dp[i][j] = dp[i-1][j-1] + 1
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

### Pattern C — Edit Distance

```python
# dp[i][j] = min ops to convert word1[:i] → word2[:j]
if word1[i-1] == word2[j-1]:
    dp[i][j] = dp[i-1][j-1]
else:
    dp[i][j] = 1 + min(
        dp[i-1][j],    # delete
        dp[i][j-1],    # insert
        dp[i-1][j-1],  # replace
    )
```

### Pattern D — 0/1 Knapsack 2D

```python
# dp[i][w] = max value using first i items, capacity w
dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + val[i])
```

### Pattern E — Longest Palindromic Subsequence

LCS(s, reverse(s)) or:

```python
# dp[i][j] LPS in s[i..j]
if s[i] == s[j]:
    dp[i][j] = dp[i+1][j-1] + 2
else:
    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
```

### Pattern F — Interval DP

```python
# dp[i][j] = best for subarray/range i..j
for length in range(2, n+1):
    for i in range(n-length+1):
        j = i + length - 1
        for k in range(i, j):
            dp[i][j] = optimal(dp[i][k], dp[k+1][j], cost(i,k,j))
```
Examples: burst balloons, matrix chain, predict the winner.

### Pattern G — DP on strings with regex

```python
# isMatch: dp[i][j] = s[:i] matches p[:j]
# handle '*' as zero-or-more of previous
```

### Pattern H — Stock DP state machine

```python
# hold[i], free[i], cool[i] transitions
```

### Filling order checklist

1. Increasing i, j from bases
2. For interval DP: increasing **length**
3. For LPS: length or i descending, j ascending

### Memory tricks

- Rolling arrays when only prev row needed
- Bitset knapsack for boolean reachability

---

## Associated LeetCode problems

### Medium

| # | Problem | Pattern |
|---|---------|---------|
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | Grid |
| 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | Obstacles |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | Grid |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | LCS |
| 583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/) | LCS |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance/) | Edit |
| 97 | [Interleaving String](https://leetcode.com/problems/interleaving-string/) | 2 strings |
| 115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) | Count |
| 516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | LPS |
| 221 | [Maximal Square](https://leetcode.com/problems/maximal-square/) | Grid square |
| 120 | [Triangle](https://leetcode.com/problems/triangle/) | Bottom-up |
| 931 | [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/) | Grid |
| 474 | [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/) | 2D knapsack |
| 309 | Stock with Cooldown | State machine |
| 518 | Coin Change II | (1D but related) |
| 718 | [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) | LCS-like |
| 877 | [Stone Game](https://leetcode.com/problems/stone-game/) | Interval / math |
| 486 | [Predict the Winner](https://leetcode.com/problems/predict-the-winner/) | Interval |
| 329 | [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) | DFS + memo |

### Hard

| # | Problem | Pattern |
|---|---------|---------|
| 10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | Regex DP |
| 44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | Regex DP |
| 312 | [Burst Balloons](https://leetcode.com/problems/burst-balloons/) | Interval |
| 87 | [Scramble String](https://leetcode.com/problems/scramble-string/) | Interval |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) | Interval |
| 174 | [Dungeon Game](https://leetcode.com/problems/dungeon-game/) | Reverse grid |
| 85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | Histogram + stack |
| 1235 | [Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) | DP + BS |
| 188 | Stock IV | State |
| 403 | Frog Jump | Set DP |

---

## Chapter exit criteria

- [ ] LCS + Edit Distance from memory
- [ ] Grid path DP with obstacles
- [ ] Interval DP length loop structure
- [ ] Compress one DP dimension when possible
