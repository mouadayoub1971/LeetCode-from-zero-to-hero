# Chapter 18 — Bit Manipulation

> Pack state into bits; XOR magic; flags without sets.

## Notion

### Operators

| Op | Meaning |
|----|---------|
| `a & b` | bits both 1 |
| `a \| b` | bits either 1 |
| `a ^ b` | bits differ |
| `~a` | flip (careful in Python unlimited) |
| `a << k` | * 2^k |
| `a >> k` | / 2^k (sign matters in Java) |

### Must-know tricks

```python
x & 1          # is odd?
x & (x-1)      # clear lowest set bit
x & -x         # isolate lowest set bit (two's complement)
x & (1 << k)   # test bit k
x | (1 << k)   # set bit k
x & ~(1 << k)  # clear bit k
x ^ (1 << k)   # toggle bit k
bin(x).count('1')  # popcount (or bit_count() in Py3.10+)
```

### XOR properties

```
a ^ a = 0
a ^ 0 = a
a ^ b ^ a = b   # commutative/associative
```

**Single number:** XOR all → the unique remains.  
**Missing number:** XOR indices with values.

### Brian Kernighan popcount

```python
def popcount(x):
    c = 0
    while x:
        x &= x - 1
        c += 1
    return c
```

### Bitmask DP (n ≤ 20)

```python
# dp[mask] = best using set of items in mask
n = len(nums)
dp = [0] * (1 << n)
for mask in range(1 << n):
    for i in range(n):
        if mask & (1 << i) == 0:
            nxt = mask | (1 << i)
            dp[nxt] = max(dp[nxt], dp[mask] + gain(i, mask))
```

### Subset enumeration of a mask

```python
sub = mask
while sub:
    # use sub
    sub = (sub - 1) & mask
```

### n & (n-1) == 0 → power of two (n > 0)

### Get sum without + 

```python
# (a^b) + ((a&b)<<1) iterative
```

### Reverse bits / reverse bytes

Loop 32 times shifting.

### When to use bits

- Track visited subset of ≤20 nodes
- Compact presence of letters (26 bits fits int)
- Pairwise XOR maximization (bit trie)
- Permission flags

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 136 | [Single Number](https://leetcode.com/problems/single-number/) |
| 191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) |
| 190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) |
| 338 | [Counting Bits](https://leetcode.com/problems/counting-bits/) |
| 268 | [Missing Number](https://leetcode.com/problems/missing-number/) |
| 231 | [Power of Two](https://leetcode.com/problems/power-of-two/) |
| 342 | [Power of Four](https://leetcode.com/problems/power-of-four/) |
| 461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance/) |
| 389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/) |

### Medium

| # | Problem |
|---|---------|
| 137 | [Single Number II](https://leetcode.com/problems/single-number-ii/) |
| 260 | [Single Number III](https://leetcode.com/problems/single-number-iii/) |
| 78 | Subsets (bitmask generation) |
| 7 | Reverse Integer (not really bits) |
| 201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) |
| 318 | [Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/) |
| 371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) |
| 1310 | [XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/) |
| 421 | [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) |
| 898 | [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-ors-of-subarrays/) |
| 1442 | [Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/) |
| 187 | [Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/) | Encode 2 bits |

### Hard

| # | Problem |
|---|---------|
| 995 | Minimum Number of K Consecutive Bit Flips |
| 847 | Shortest Path Visiting All Nodes | Bitmask BFS |
| 1494 | [Parallel Courses II](https://leetcode.com/problems/parallel-courses-ii/) | Bitmask DP |
| 464 | [Can I Win](https://leetcode.com/problems/can-i-win/) | Bitmask game |
| 982 | [Triples with Bitwise AND Equal To Zero](https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/) |

---

## Chapter exit criteria

- [ ] XOR single-number family
- [ ] Set/clear/test/toggle bit
- [ ] Bitmask DP for n≤20
- [ ] popcount & power-of-two checks
