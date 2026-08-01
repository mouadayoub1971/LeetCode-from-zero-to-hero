# Chapter 01 — Arrays & Hashing

> The #1 most used tool on LeetCode. Everything builds on this.

## Notion

### Arrays

- Contiguous memory, O(1) index access
- Insert/delete in middle is O(n)
- Common ops: prefix sums, in-place swap, two-index walks

### Hash Map / Hash Set

| Structure | Use when |
|-----------|----------|
| `set` | Existence, uniqueness, visited |
| `map` (dict) | Frequency, index of value, grouping |
| `defaultdict(list)` | Group anagrams, graph adjacency |

**Average O(1)** insert/lookup/delete. Worst O(n) — ignore unless asked.

### Core patterns

#### 1. Complement lookup (Two Sum family)

```python
def two_sum(nums, target):
    seen = {}  # value -> index
    for i, x in enumerate(nums):
        need = target - x
        if need in seen:
            return [seen[need], i]
        seen[x] = i
```

#### 2. Frequency counting

```python
from collections import Counter
cnt = Counter(s)
# or
freq = {}
for c in s:
    freq[c] = freq.get(c, 0) + 1
```

#### 3. Grouping by key

```python
groups = {}
for word in strs:
    key = tuple(sorted(word))  # or fixed 26-count tuple
    groups.setdefault(key, []).append(word)
```

#### 4. Prefix sums (subarray sum queries)

```python
# prefix[i] = sum of nums[0..i-1]
prefix = [0]
for x in nums:
    prefix.append(prefix[-1] + x)
# sum(nums[l..r]) inclusive = prefix[r+1] - prefix[l]
```

#### 5. Subarray sum equals K (hash + prefix)

```python
def subarray_sum(nums, k):
    count = 0
    pref = 0
    seen = {0: 1}  # prefix_sum -> frequency
    for x in nums:
        pref += x
        count += seen.get(pref - k, 0)
        seen[pref] = seen.get(pref, 0) + 1
    return count
```

#### 6. Encode unique state as key

- Sorted string / tuple of counts
- Frobenius (bitmask) for small alphabets
- `(i, j)` coordinate as key

### Invariants to remember

- Hash map does **not** preserve order (use ordered structures if needed)
- For “first unique”, track count + first index, or OrderedDict
- When values are range-limited (0–1000), array beats hash

---

## Complexity cheatsheet

| Op | Time | Space |
|----|------|-------|
| Build freq map | O(n) | O(k) distinct |
| Two Sum one-pass | O(n) | O(n) |
| Group anagrams | O(n * m log m) or O(n * m) with count key | O(n m) |
| Prefix sum build | O(n) | O(n) |
| Range sum query | O(1) after build | O(n) |

---

## Associated LeetCode problems

### Easy — pure pattern

| # | Problem | Pattern |
|---|---------|---------|
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | Set |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | Freq count |
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | Complement map |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | Group by key |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | Freq + bucket/heap |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Prefix/suffix products |
| 128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | Set + stretch |
| 271 | Encode and Decode Strings (Premium) | Delimiter encoding |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | Sets for row/col/box |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | Vertical scan |
| 118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | Build array |
| 560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | Prefix + hash |

### Medium — deepen

| # | Problem | Pattern |
|---|---------|---------|
| 49 | Group Anagrams | (if not done) |
| 128 | Longest Consecutive Sequence | O(n) set trick |
| 238 | Product Except Self | No division |
| 36 | Valid Sudoku | Multi-set validation |
| 554 | [Brick Wall](https://leetcode.com/problems/brick-wall/) | Edge frequency |
| 525 | [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | Prefix + first index |
| 974 | [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | Modulo prefix |
| 41 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | Index-as-hash in-place |

### Hard

| # | Problem | Pattern |
|---|---------|---------|
| 76 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Hash + window (preview Ch.03) |
| 41 | First Missing Positive | In-place hashing |

---

## Must-memorize solution: Longest Consecutive O(n)

```python
def longestConsecutive(nums):
    s = set(nums)
    best = 0
    for x in s:
        if x - 1 not in s:  # start of a streak only
            length = 1
            while x + length in s:
                length += 1
            best = max(best, length)
    return best
```

---

## Chapter exit criteria

- [ ] Two Sum / Anagram / Contains Duplicate in < 5 min each
- [ ] Explain prefix sum + hash for subarray sum
- [ ] Longest Consecutive in O(n) without sorting
- [ ] Product Except Self without division
