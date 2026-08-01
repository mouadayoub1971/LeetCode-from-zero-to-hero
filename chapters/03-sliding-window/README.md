# Chapter 03 — Sliding Window

> Optimal tool for contiguous subarray / substring problems.

## Notion

Maintain a window `[L, R]` over a sequence. Expand `R`, shrink `L` when the window becomes invalid (or when you need a fixed size).

### When to use

Keywords: **subarray**, **substring**, **contiguous**, longest/shortest with condition, at most K distinct, all anagrams, max sum of size K.

### Two types

| Type | Description | Example |
|------|-------------|---------|
| Fixed size | Window length = k always | Max sum of k elements |
| Variable size | Grow/shrink by condition | Longest substring without repeat |

### Template — variable window (most important)

```python
def sliding_window(s):
    from collections import defaultdict
    window = defaultdict(int)  # or Counter / set
    L = 0
    best = 0  # or math.inf for minimum
    for R, x in enumerate(s):
        # 1. add s[R] into window
        window[x] += 1

        # 2. shrink while INVALID
        while window_invalid(window):
            window[s[L]] -= 1
            if window[s[L]] == 0:
                del window[s[L]]
            L += 1

        # 3. update answer with valid window s[L..R]
        best = max(best, R - L + 1)
    return best
```

### Template — fixed window

```python
def max_sum_k(nums, k):
    cur = sum(nums[:k])
    best = cur
    for i in range(k, len(nums)):
        cur += nums[i] - nums[i - k]
        best = max(best, cur)
    return best
```

### Classic problems mapped

| Problem idea | Invalid condition | Answer type |
|--------------|-------------------|-------------|
| Longest no repeat | `freq[c] > 1` | max length |
| Longest ≤ K distinct | `len(map) > K` | max length |
| Min window covering t | not covering → keep growing; when cover shrink | min length |
| Max consecutive 1s with ≤ K flips | `zeros > K` | max length |
| Find all anagrams | window size = len(p), counts match | list of starts |

### Minimum window substring (hard template)

```python
from collections import Counter

def minWindow(s, t):
    need = Counter(t)
    missing = len(t)
    L = 0
    best = (float('inf'), 0, 0)  # len, start, end
    for R, c in enumerate(s):
        if need[c] > 0:
            missing -= 1
        need[c] -= 1
        while missing == 0:
            if R - L + 1 < best[0]:
                best = (R - L + 1, L, R)
            need[s[L]] += 1
            if need[s[L]] > 0:
                missing += 1
            L += 1
    return "" if best[0] == float('inf') else s[best[1]:best[2]+1]
```

### At most K → exactly K trick

```
exactly(K) = at_most(K) - at_most(K-1)
```
Useful for “subarrays with K different integers”.

### Common mistakes

- Forgetting to delete zero-count keys (breaks “distinct” count)
- Updating answer while window is still invalid
- Using `while` vs `if` for shrink (usually `while`)
- Off-by-one on length `R - L + 1`

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 643 | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) |
| 219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |

### Medium (core)

| # | Problem | Idea |
|---|---------|------|
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Classic variable |
| 424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | maxf + window |
| 567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | Fixed anagram |
| 438 | [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | Fixed anagram |
| 209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | Shrink for min |
| 904 | [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) | At most 2 distinct |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | Flip ≤ K zeros |
| 1456 | [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | Fixed |
| 713 | [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | Product window |
| 930 | [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | at_most trick |
| 992 | [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | exactly = at_most |

### Hard

| # | Problem |
|---|---------|
| 76 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | Monotonic deque (Ch.23) |
| 480 | [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) | Two heaps |

---

## Chapter exit criteria

- [ ] Code Longest Substring Without Repeating from memory
- [ ] Code Min Window Substring and explain `need`/`missing`
- [ ] Apply at_most(K) − at_most(K−1)
- [ ] Distinguish fixed vs variable window instantly
