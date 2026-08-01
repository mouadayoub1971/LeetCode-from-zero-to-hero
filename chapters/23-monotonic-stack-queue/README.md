# Chapter 23 — Monotonic Stack & Queue

> Next greater/smaller in O(n). Window max in O(n).

## Notion

### Monotonic stack

Stack stays sorted (increasing or decreasing). When a new element breaks order, pop and **resolve answers** for popped indices.

### Next Greater Element template

```python
def nextGreater(nums):
    n = len(nums)
    ans = [-1] * n
    st = []  # indices; values decreasing from bottom to top
    for i, x in enumerate(nums):
        while st and nums[st[-1]] < x:
            ans[st.pop()] = x
        st.append(i)
    return ans
```

| Goal | Stack order (bottom → top) | Pop when |
|------|----------------------------|----------|
| Next greater | Decreasing | `nums[st] < x` |
| Next smaller | Increasing | `nums[st] > x` |
| Prev greater | Decreasing, scan right→left or store while building | similar |

### Largest rectangle in histogram

For each bar i, width = right_smaller[i] - left_smaller[i] - 1; area = height[i]*width.  
Use monotonic increasing stack of indices.

```python
def largestRectangleArea(heights):
    heights = [0] + heights + [0]
    st = []
    best = 0
    for i, h in enumerate(heights):
        while st and heights[st[-1]] > h:
            H = heights[st.pop()]
            width = i - st[-1] - 1
            best = max(best, H * width)
        st.append(i)
    return best
```

### Monotonic deque — sliding window maximum

```python
from collections import deque

def maxSlidingWindow(nums, k):
    dq = deque()  # indices, values decreasing
    out = []
    for i, x in enumerate(nums):
        while dq and nums[dq[-1]] < x:
            dq.pop()
        dq.append(i)
        if dq[0] <= i - k:
            dq.popleft()
        if i >= k - 1:
            out.append(nums[dq[0]])
    return out
```

### Stock span / online queries

Monotonic stack of (price, span) or indices.

### Sum of subarray minimums

For each i, count subarrays where `arr[i]` is minimum using prev/next smaller → contribution `arr[i] * left * right`.

### Common mistakes

- Storing values instead of indices when need distance/width  
- Strict vs non-strict inequality (duplicates)  
- Forgetting sentinels `0` height at ends for histogram  

---

## Associated LeetCode problems

### Easy / Medium

| # | Problem |
|---|---------|
| 496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) |
| 503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) | Circular |
| 739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) |
| 901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span/) |
| 402 | [Remove K Digits](https://leetcode.com/problems/remove-k-digits/) |
| 316 | [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) |
| 1081 | [Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/) |
| 456 | [132 Pattern](https://leetcode.com/problems/132-pattern/) |
| 962 | [Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/) |
| 581 | [Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/) |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | Stack or two ptr |
| 1019 | [Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/) |
| 1475 | [Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) |

### Hard

| # | Problem |
|---|---------|
| 84 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) |
| 85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) |
| 907 | [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) |
| 2104 | [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) |
| 1944 | [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/) |
| 862 | [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/) | Mono deque + prefix |
| 1438 | [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) |

---

## Chapter exit criteria

- [ ] Next Greater Element template cold
- [ ] Daily Temperatures
- [ ] Histogram largest rectangle
- [ ] Sliding window maximum deque
