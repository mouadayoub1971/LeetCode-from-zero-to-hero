# Chapter 05 — Binary Search

> Find in O(log n) on sorted data — or on a monotonic answer space.

## Notion

Binary search repeatedly halves a search range. Works when the predicate is **monotonic**: once true, stays true (or once false, stays false).

### Two mental models

1. **Search in a sorted array** (classic index search)
2. **Binary search on the answer** (minimize/maximize X such that ` cond(X)` is true)

### Template 1 — classic lower bound

```python
def lower_bound(nums, target):
    """First index i with nums[i] >= target (or n)."""
    lo, hi = 0, len(nums)  # hi is exclusive
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid
    return lo
```

### Template 2 — find exact

```python
def search(nums, target):
    lo, hi = 0, len(nums) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1
```

### Template 3 — binary search on answer

```python
def minimize_capacity(weights, days):
    def can(cap):
        need, cur = 1, 0
        for w in weights:
            if cur + w > cap:
                need += 1
                cur = 0
            cur += w
        return need <= days

    lo, hi = max(weights), sum(weights)
    while lo < hi:
        mid = (lo + hi) // 2
        if can(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo
```

**Rule:** if `can(mid)` is true, try smaller (`hi = mid`); else `lo = mid + 1`.

### Rotated sorted array

```python
def search_rotated(nums, target):
    lo, hi = 0, len(nums) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if nums[mid] == target:
            return mid
        if nums[lo] <= nums[mid]:  # left half sorted
            if nums[lo] <= target < nums[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        else:  # right half sorted
            if nums[mid] < target <= nums[hi]:
                lo = mid + 1
            else:
                hi = mid - 1
    return -1
```

### Avoid infinite loops

| Pattern | Condition | Update |
|---------|-----------|--------|
| `lo < hi`, hi exclusive | `if f(mid): hi=mid else lo=mid+1` | Always terminates |
| `lo <= hi` | classic exact find | `lo=mid+1` / `hi=mid-1` |
| Never `lo = mid` with `lo < hi` without care | Can infinite loop | Use `mid = (lo+hi+1)//2` if taking right |

### When NOT binary search

- Unsorted with no monotonic predicate
- Need all matches listed (may still find bounds then scan)
- n is tiny (linear is fine)

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 704 | [Binary Search](https://leetcode.com/problems/binary-search/) |
| 35 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) |
| 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) |
| 374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) |
| 278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) |
| 367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) |

### Medium

| # | Problem | Type |
|---|---------|------|
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | Rotated |
| 81 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | Duplicates |
| 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | Rotated |
| 162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/) | Unimodal |
| 34 | [Find First and Last Position](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | Bounds |
| 74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | Virtual 1D |
| 875 | [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | On answer |
| 1011 | [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | On answer |
| 410 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | On answer |
| 1482 | [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | On answer |
| 540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/) | Parity |
| 240 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) | Staircase |
| 378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | On answer |

### Hard

| # | Problem |
|---|---------|
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) |
| 410 | Split Array Largest Sum |
| 668 | [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) |

---

## Chapter exit criteria

- [ ] Write lower_bound without bugs
- [ ] Solve Koko / Ship Packages (binary on answer)
- [ ] Search rotated array
- [ ] Explain monotonic predicate in your own words
