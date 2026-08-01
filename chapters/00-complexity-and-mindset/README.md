# Chapter 00 — Complexity & Problem-Solving Mindset

> Master this before grinding problems. Speed without structure = wasted months.

## Notion

### 1. Big-O (what interviewers care about)

| Complexity | Name | Example | n = 10^5 OK? |
|------------|------|---------|--------------|
| O(1) | Constant | Hash lookup | Yes |
| O(log n) | Logarithmic | Binary search | Yes |
| O(n) | Linear | Single pass | Yes |
| O(n log n) | Linearithmic | Sort | Yes |
| O(n²) | Quadratic | Nested loops | Only if n ≤ 10³–10⁴ |
| O(2ⁿ) | Exponential | Subsets brute | n ≤ 20–22 |
| O(n!) | Factorial | Permutations brute | n ≤ 10–11 |

**Space complexity** matters too: recursion depth, hash maps, DP tables.

### 2. Constraints → algorithm chooser

| Constraint on n | Likely approach |
|-----------------|-----------------|
| n ≤ 10 | Brute force / backtracking all perms |
| n ≤ 20 | Bitmask DP / 2ⁿ backtracking |
| n ≤ 100 | O(n³) maybe OK |
| n ≤ 1,000 | O(n²) OK |
| n ≤ 10⁵ | O(n) or O(n log n) |
| n ≤ 10⁶+ | O(n) or better, careful constants |
| Need answer in sorted space | Binary search on answer |

### 3. Universal solve framework (U.P.E.R.)

```
U — Understand
    Restate problem. Inputs? Outputs? Constraints? Examples?
    What is INVALID input? Duplicates? Negatives? Empty?

P — Plan
    Brute force first (always). Complexity?
    Which pattern fits? (see Chapter 26)
    Can I sort? Hash? Two pointers? DP state?

E — Execute
    Write clean code. Name variables well.
    Handle edge cases first or last deliberately.

R — Review
    Trace 1 example by hand.
    State time/space.
    What breaks if n is max?
```

### 4. Pattern recognition questions

Ask yourself in order:

1. Is the input **sorted** or can I sort? → binary search / two pointers
2. Do I need **frequency / existence**? → hash map/set
3. **Subarray / substring** with condition? → sliding window / prefix sum
4. **Tree / hierarchy**? → DFS/BFS
5. **Graph / relations**? → DFS/BFS / Union-Find / topo
6. **Optimal count/sum/ways** with overlapping subproblems? → DP
7. **All configurations** under constraints? → backtracking
8. **Top K / running median**? → heap
9. **Dependencies / order**? → topological sort
10. **Next greater / smaller**? → monotonic stack

### 5. Complexity proof mini-skills

- **Amortized analysis**: two pointers each move at most n times → O(n)
- **Master theorem intuition**: divide & conquer T(n) = 2T(n/2) + O(n) → O(n log n)
- **DP state count × transition cost** = total time

### 6. Edge cases checklist (memorize)

- Empty input `[]` / `""` / `null`
- Single element
- All equal elements
- Already sorted / reverse sorted
- Negatives and zeros
- Integer overflow (use long in C++/Java)
- Duplicates when uniqueness assumed
- Disconnected graph / empty tree
- Odd/even length (palindromes, middle node)

---

## Templates

### Timing your thoughts (interview)

```
0–2 min   Clarify + examples
2–5 min   Brute force + complexity
5–10 min  Optimal approach discussion
10–30 min Code
30–35 min Test + complexity statement
```

### Complexity comment habit

```python
# Time: O(n log n) — sort dominates
# Space: O(n) — hash map of frequencies
```

---

## Associated LeetCode problems

These train **thinking**, not a data structure.

| # | Problem | Difficulty | Focus |
|---|---------|------------|--------|
| 1 | [1. Two Sum](https://leetcode.com/problems/two-sum/) | Easy | Brute → hash optimization story |
| 2 | [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | Easy | Set vs sort tradeoff |
| 3 | [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/) | Easy | Counting complexity |
| 4 | [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | Easy | Two pointers + edge cases |
| 5 | [704. Binary Search](https://leetcode.com/problems/binary-search/) | Easy | Log n baseline |
| 6 | [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | Medium | Brute O(n²) → Kadane O(n) |
| 7 | [15. 3Sum](https://leetcode.com/problems/3sum/) | Medium | Sort + two pointers reasoning |
| 8 | [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Medium | Why greedy two pointers works |

### Practice exercise (no LC)

For each problem above, write **before coding**:

```
Brute force: _____  Time: _____
Better idea: _____  Time: _____
Why better is correct: _____
Edge cases: _____
```

---

## Chapter exit criteria

- [ ] You can convert constraints → target complexity in < 10 seconds
- [ ] You always state brute force before optimal
- [ ] You list edge cases before coding
- [ ] You can explain Big-O of nested loops, recursion, and hash ops
