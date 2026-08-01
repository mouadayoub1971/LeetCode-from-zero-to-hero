# Chapter 10 — Backtracking

> Explore all candidates; undo choices. Subsets, permutations, combinations, constraint search.

## Notion

Backtracking = DFS on an implicit decision tree:

```
choose → explore → unchoose
```

### Universal template

```python
def backtrack(state):
    if is_solution(state):
        record(state)
        return
    for choice in choices(state):
        if not valid(choice, state):
            continue
        apply(choice, state)
        backtrack(state)
        undo(choice, state)  # unchoose
```

### Decision tree types

| Problem type | Tree shape | Complexity |
|--------------|------------|------------|
| Subsets | Include / skip each element | O(2ⁿ) |
| Permutations | Pick unused elements | O(n!) |
| Combinations | Pick next with order fixed | O(C(n,k)) |
| Partition / sudoku | Try values with pruning | varies |

### Subsets

```python
def subsets(nums):
    res, path = [], []
    def bt(start):
        res.append(path[:])
        for i in range(start, len(nums)):
            path.append(nums[i])
            bt(i + 1)
            path.pop()
    bt(0)
    return res
```

### Subsets with duplicates

Sort first; skip `nums[i] == nums[i-1]` at same depth:

```python
if i > start and nums[i] == nums[i-1]:
    continue
```

### Permutations

```python
def permute(nums):
    res = []
    used = [False] * len(nums)
    def bt(path):
        if len(path) == len(nums):
            res.append(path[:])
            return
        for i in range(len(nums)):
            if used[i]:
                continue
            used[i] = True
            path.append(nums[i])
            bt(path)
            path.pop()
            used[i] = False
    bt([])
    return res
```

### Combination sum (reuse allowed)

```python
def combinationSum(cands, target):
    res, path = [], []
    cands.sort()
    def bt(start, remain):
        if remain == 0:
            res.append(path[:])
            return
        for i in range(start, len(cands)):
            if cands[i] > remain:
                break
            path.append(cands[i])
            bt(i, remain - cands[i])  # i not i+1 → reuse
            path.pop()
    bt(0, target)
    return res
```

### N-Queens pruning

Track cols, diag1 (r-c), diag2 (r+c) as sets.

### Board DFS (Word Search)

Mark cell visited (`#`), recurse 4 dirs, unmark.

### Pruning tips (critical for Hard)

- Sort and break early when remaining too big/small
- Prefer tightest constraint first (MRV)
- Bitmasks for small n (n ≤ 20)
- Pass immutable index ranges instead of copying arrays

### Backtracking vs DP

- Need **all solutions** or constructions → backtracking
- Need **count / optimal value** with overlapping states → DP
- Sometimes count with backtracking + memo = DP

---

## Associated LeetCode problems

### Easy / Medium core

| # | Problem | Type |
|---|---------|------|
| 78 | [Subsets](https://leetcode.com/problems/subsets/) | Subsets |
| 90 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | Duplicates |
| 46 | [Permutations](https://leetcode.com/problems/permutations/) | Perms |
| 47 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | Dup perms |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | Reuse |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | No reuse + dup |
| 77 | [Combinations](https://leetcode.com/problems/combinations/) | C(n,k) |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | Map DFS |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | Constraints |
| 79 | [Word Search](https://leetcode.com/problems/word-search/) | Board |
| 131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | Partition |
| 93 | [Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/) | Partition |
| 216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | k numbers |

### Hard

| # | Problem |
|---|---------|
| 51 | [N-Queens](https://leetcode.com/problems/n-queens/) |
| 52 | [N-Queens II](https://leetcode.com/problems/n-queens-ii/) |
| 37 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) |
| 212 | [Word Search II](https://leetcode.com/problems/word-search-ii/) |
| 10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | DP better |
| 44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | DP better |

---

## Chapter exit criteria

- [ ] Subsets / Perms / CombSum from memory
- [ ] Duplicate-skipping rule
- [ ] N-Queens with diag sets
- [ ] Explain choose/explore/unchoose on whiteboard
