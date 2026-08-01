# Chapter 20 — Segment Tree & Fenwick (BIT)

> Range queries + point updates in O(log n). Hard LC / contest power tools.

## Notion

### When you need them

- Many queries: range sum / min / max / GCD
- Array updates between queries
- Inversion count (with coordinate compression)
- Range update + point query (diff + BIT)

Prefix sums alone **fail** if values update.

### Fenwick Tree (Binary Indexed Tree) — range sum

```python
class BIT:
    def __init__(self, n):
        self.n = n
        self.f = [0] * (n + 1)  # 1-indexed

    def add(self, i, delta):  # point update
        while i <= self.n:
            self.f[i] += delta
            i += i & -i

    def sum(self, i):  # prefix sum [1..i]
        s = 0
        while i > 0:
            s += self.f[i]
            i -= i & -i
        return s

    def range_sum(self, l, r):  # inclusive
        return self.sum(r) - self.sum(l - 1)
```

Build: `add(i, nums[i-1])` for all i.  
**Limitation:** classic BIT is for invertible ops (sum, XOR). Min/max need segment tree (or specialized).

### Segment Tree — general range query

```python
class SegTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.t = [0] * (4 * self.n)
        self._build(arr, 1, 0, self.n - 1)

    def _build(self, arr, node, l, r):
        if l == r:
            self.t[node] = arr[l]
            return
        m = (l + r) // 2
        self._build(arr, node*2, l, m)
        self._build(arr, node*2+1, m+1, r)
        self.t[node] = self.t[node*2] + self.t[node*2+1]  # or min/max

    def update(self, idx, val, node=1, l=None, r=None):
        if l is None: l, r = 0, self.n - 1
        if l == r:
            self.t[node] = val
            return
        m = (l + r) // 2
        if idx <= m:
            self.update(idx, val, node*2, l, m)
        else:
            self.update(idx, val, node*2+1, m+1, r)
        self.t[node] = self.t[node*2] + self.t[node*2+1]

    def query(self, ql, qr, node=1, l=None, r=None):
        if l is None: l, r = 0, self.n - 1
        if qr < l or r < ql:
            return 0  # identity for sum
        if ql <= l and r <= qr:
            return self.t[node]
        m = (l + r) // 2
        return self.query(ql, qr, node*2, l, m) + self.query(ql, qr, node*2+1, m+1, r)
```

### Lazy propagation (range updates)

Store pending updates on nodes; push down when visiting children. Needed for range add + range sum.

### Coordinate compression

When values are huge but count is n: map values to ranks `1..n` before BIT.

### Inversion count

```python
# process right-to-left or left-to-right with BIT on ranks
# count how many already seen are smaller/larger
```

### Sqrt decomposition (alternative)

Blocks of size √n; simpler to write, O(√n) query — sometimes enough.

---

## Associated LeetCode problems

### Medium

| # | Problem | Tool |
|---|---------|------|
| 307 | [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) | BIT/Seg |
| 303 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | Prefix |
| 304 | [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) | 2D prefix |
| 315 | [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) | BIT/Merge |
| 327 | [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/) | BIT/Merge |
| 493 | [Reverse Pairs](https://leetcode.com/problems/reverse-pairs/) | Merge/BIT |
| 1505 | [Minimum Possible Integer After at Most K Adjacent Swaps On Digits](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/) | BIT |

### Hard

| # | Problem |
|---|---------|
| 218 | [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) | Sweep + heap/seg |
| 715 | [Range Module](https://leetcode.com/problems/range-module/) | Seg / ordered set |
| 850 | [Rectangle Area II](https://leetcode.com/problems/rectangle-area-ii/) | Sweep + seg |
| 1649 | [Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions/) | BIT |
| 2286 | [Booking Concert Tickets in Groups](https://leetcode.com/problems/booking-concert-tickets-in-groups/) | SegTree |
| 3165 | Maximum Score of Non-overlapping Intervals (varies) |

> Note: Many FAANG interviews rarely require full segment trees; still valuable for Hard LC and contests.

---

## Chapter exit criteria

- [ ] Implement BIT add + prefix sum
- [ ] Implement segment tree point update + range sum
- [ ] Solve Range Sum Query Mutable
- [ ] Count smaller after self (merge sort or BIT)
