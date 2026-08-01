# Chapter 02 — Two Pointers

> Collapse O(n²) pair/search logic into O(n) by smart pointer movement.

## Notion

Two pointers = maintain **two indices** with an invariant, move them based on a condition.

### Flavors

| Flavor | Setup | Use |
|--------|-------|-----|
| Opposite ends | `L=0, R=n-1` | Sorted pair sum, container water, palindrome |
| Same direction | `slow, fast` | Remove duplicates, partition, cycle (lists) |
| Read/Write | `write` trails `read` | In-place filter/compress |
| Three pointers | Dutch flag | 3-way partition (sort colors) |

### When to use

- Array is **sorted** (or you can sort)
- Looking for **pair/triplet** with sum condition
- Comparing from outside in (palindrome)
- In-place removal without extra array
- Partition around a pivot

### Pattern A — Opposite direction (sorted pair)

```python
def two_sum_sorted(nums, target):  # nums sorted
    L, R = 0, len(nums) - 1
    while L < R:
        s = nums[L] + nums[R]
        if s == target:
            return [L, R]
        if s < target:
            L += 1
        else:
            R -= 1
    return []
```

**Why correct:** if sum too small, need bigger left; if too big, need smaller right. Sorted invariant.

### Pattern B — 3Sum skeleton

```python
def three_sum(nums):
    nums.sort()
    res = []
    n = len(nums)
    for i in range(n):
        if i and nums[i] == nums[i-1]:
            continue  # skip duplicate anchors
        L, R = i + 1, n - 1
        while L < R:
            s = nums[i] + nums[L] + nums[R]
            if s == 0:
                res.append([nums[i], nums[L], nums[R]])
                L += 1
                R -= 1
                while L < R and nums[L] == nums[L-1]:
                    L += 1
                while L < R and nums[R] == nums[R+1]:
                    R -= 1
            elif s < 0:
                L += 1
            else:
                R -= 1
    return res
```

### Pattern C — Same direction (remove duplicates in-place)

```python
def remove_duplicates(nums):  # sorted
    if not nums:
        return 0
    w = 1
    for r in range(1, len(nums)):
        if nums[r] != nums[w-1]:
            nums[w] = nums[r]
            w += 1
    return w
```

### Pattern D — Container with most water

```python
def max_area(h):
    L, R, best = 0, len(h) - 1, 0
    while L < R:
        best = max(best, min(h[L], h[R]) * (R - L))
        if h[L] < h[R]:
            L += 1  # only taller left can improve
        else:
            R -= 1
    return best
```

### Pattern E — Dutch National Flag (3 colors)

```python
def sort_colors(nums):
    lo = mid = 0
    hi = len(nums) - 1
    while mid <= hi:
        if nums[mid] == 0:
            nums[lo], nums[mid] = nums[mid], nums[lo]
            lo += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:
            nums[mid], nums[hi] = nums[hi], nums[mid]
            hi -= 1
```

### Common mistakes

- Off-by-one: `L < R` vs `L <= R`
- Forgetting duplicate skips in k-sum
- Moving both pointers when only one should move
- Sorting when order of indices matters (Two Sum I vs II)

---

## Associated LeetCode problems

### Easy

| # | Problem | Flavor |
|---|---------|--------|
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | Opposite |
| 167 | [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Opposite |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Read/Write |
| 27 | [Remove Element](https://leetcode.com/problems/remove-element/) | Read/Write |
| 283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | Read/Write |
| 344 | [Reverse String](https://leetcode.com/problems/reverse-string/) | Opposite |
| 977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | Opposite (negatives) |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | From the end |

### Medium

| # | Problem | Flavor |
|---|---------|--------|
| 15 | [3Sum](https://leetcode.com/problems/3sum/) | Anchor + opposite |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Greedy opposite |
| 42 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | Two pointers / stack |
| 75 | [Sort Colors](https://leetcode.com/problems/sort-colors/) | Dutch flag |
| 18 | [4Sum](https://leetcode.com/problems/4sum/) | Generalize k-sum |
| 16 | [3Sum Closest](https://leetcode.com/problems/3sum-closest/) | Track best |
| 611 | [Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) | Sorted + two ptr |
| 881 | [Boats to Save People](https://leetcode.com/problems/boats-to-save-people/) | Greedy opposite |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | Reverse tricks |

### Hard

| # | Problem | Notes |
|---|---------|-------|
| 42 | Trapping Rain Water | Two-pointer O(1) space version |
| 407 | [Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/) | Heap BFS (later) |

---

## Chapter exit criteria

- [ ] Implement 3Sum from scratch with duplicate handling
- [ ] Explain why Container With Most Water is O(n)
- [ ] Dutch flag sort in one pass
- [ ] In-place remove duplicates / move zeroes
