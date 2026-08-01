# Chapter 15 — Greedy

> Local best choice → global optimum (when structure allows).

## Notion

Greedy works when you can **prove** that a local choice never blocks a better global solution (exchange argument / greedy stays ahead).

If you can't see a proof, try DP. Many DP problems have greedy shortcuts.

### Common greedy patterns

#### 1. Sort then pick

Sort by start, end, ratio, or deadline — then scan once.

```python
# activity selection: sort by end time, take next compatible
intervals.sort(key=lambda x: x[1])
count, end = 0, -inf
for s, e in intervals:
    if s >= end:
        count += 1
        end = e
```

#### 2. Jump Game family

```python
far = 0
for i in range(len(nums)):
    if i > far: return False
    far = max(far, i + nums[i])
return True
```

#### 3. Gas station circular

```python
# if total gas >= total cost, unique start exists
# track tank; when negative reset start to i+1
```

#### 4. Huffman-style / always merge smallest

Use heap: last stone weight, minimum cost to connect sticks.

#### 5. Assign cookies / two pointers after sort

```python
g.sort(); s.sort()
i = j = 0
while i < len(g) and j < len(s):
    if s[j] >= g[i]:
        i += 1
    j += 1
return i
```

#### 6. Candies / rating peaks

Two-pass: left-to-right ensure higher than left neighbor; right-to-left vs right.

#### 7. Remove K digits (monotonic stack greedy)

Build smallest number by popping larger digits when possible.

#### 8. Interval covering / jump II

Track current end and farthest in range (BFS layers without queue).

### How to verify greedy in interview

1. State the choice rule clearly  
2. Give exchange argument sketch: “any optimal that differs can swap to our choice without worsening”  
3. Check counter-examples for wrong sort keys  
4. Confirm with small brute force if n tiny  

### Greedy vs DP cheat

| Need | Prefer |
|------|--------|
| Count of ways | DP |
| Optimal value with overlapping choices | DP |
| Scheduling with clear order | Greedy |
| “Always take max available” works | Greedy + heap |

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 455 | [Assign Cookies](https://leetcode.com/problems/assign-cookies/) |
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) |
| 605 | [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) |
| 860 | [Lemonade Change](https://leetcode.com/problems/lemonade-change/) |
| 976 | [Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/) |
| 1217 | [Minimum Cost to Move Chips](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/) |

### Medium

| # | Problem |
|---|---------|
| 55 | [Jump Game](https://leetcode.com/problems/jump-game/) |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/) |
| 846 | [Hand of Straights](https://leetcode.com/problems/hand-of-straights/) |
| 1899 | [Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/) |
| 763 | [Partition Labels](https://leetcode.com/problems/partition-labels/) |
| 678 | [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) |
| 738 | [Monotone Increasing Digits](https://leetcode.com/problems/monotone-increasing-digits/) |
| 402 | [Remove K Digits](https://leetcode.com/problems/remove-k-digits/) |
| 621 | [Task Scheduler](https://leetcode.com/problems/task-scheduler/) |
| 881 | [Boats to Save People](https://leetcode.com/problems/boats-to-save-people/) |
| 1353 | [Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/) |
| 1568 | Minimum Number of Days to Disconnect Island (Hard-ish) |
| 1029 | [Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/) |
| 406 | [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/) |
| 452 | [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | Intervals |

### Hard

| # | Problem |
|---|---------|
| 135 | [Candy](https://leetcode.com/problems/candy/) |
| 321 | [Create Maximum Number](https://leetcode.com/problems/create-maximum-number/) |
| 995 | [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/) |
| 630 | [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) |

---

## Chapter exit criteria

- [ ] Jump Game I & II greedy
- [ ] Gas Station one-pass
- [ ] Sort-by-end interval selection
- [ ] Can articulate why greedy is safe for 2 problems
