# Chapter 09 — Heap / Priority Queue

> Always grab the current min or max in O(log n). King of Top-K.

## Notion

Binary heap = complete binary tree in an array.

| Op | Time |
|----|------|
| peek min/max | O(1) |
| push | O(log n) |
| pop | O(log n) |
| build heap | O(n) |

Python: `heapq` is **min-heap**. For max-heap, push `-x`.

```python
import heapq
h = []
heapq.heappush(h, 3)
heapq.heappush(h, 1)
heapq.heappop(h)  # 1
```

### Pattern A — Top K frequent / largest

```python
def topKFrequent(nums, k):
    from collections import Counter
    import heapq
    count = Counter(nums)
    # nlargest on (freq, num)
    return [x for x, _ in heapq.nlargest(k, count.items(), key=lambda kv: kv[1])]

# or maintain size-k min-heap of frequencies
```

**Bucket sort** alternative when values allow: O(n).

### Pattern B — Kth largest in stream

```python
class KthLargest:
    def __init__(self, k, nums):
        self.k = k
        self.h = nums
        heapq.heapify(self.h)
        while len(self.h) > k:
            heapq.heappop(self.h)

    def add(self, val):
        heapq.heappush(self.h, val)
        if len(self.h) > self.k:
            heapq.heappop(self.h)
        return self.h[0]
```

### Pattern C — Merge K sorted lists

```python
def mergeKLists(lists):
    h = []
    for i, node in enumerate(lists):
        if node:
            heapq.heappush(h, (node.val, i, node))
    dummy = cur = ListNode()
    while h:
        val, i, node = heapq.heappop(h)
        cur.next = node
        cur = cur.next
        if node.next:
            heapq.heappush(h, (node.next.val, i, node.next))
    return dummy.next
```

### Pattern D — Two heaps (median)

```python
# lo = max-heap (via negatives), hi = min-heap
# invariant: len(lo) == len(hi) or len(lo) == len(hi)+1
```

### Pattern E — Task / interval scheduling with heap

Push end times; free the earliest room when a new meeting starts.

### Pattern F — Dijkstra (see Ch.25)

Min-heap of `(dist, node)`.

### When heap vs sort

- Need **one-time** top-K of static array → sort O(n log n) or quickselect O(n)
- Need **streaming** / repeated extract → heap
- Need **all sorted** → just sort

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) |
| 1046 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) |
| 215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Medium but core |
| 506 | [Relative Ranks](https://leetcode.com/problems/relative-ranks/) |

### Medium

| # | Problem |
|---|---------|
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) |
| 215 | Kth Largest Element |
| 973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) |
| 621 | [Task Scheduler](https://leetcode.com/problems/task-scheduler/) |
| 767 | [Reorganize String](https://leetcode.com/problems/reorganize-string/) |
| 451 | [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) |
| 658 | [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) |
| 373 | [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) |
| 2542 | [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/) |
| 1834 | [Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/) |
| 1642 | [Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/) |

### Hard

| # | Problem |
|---|---------|
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) |
| 295 | [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | Deque better |
| 502 | [IPO](https://leetcode.com/problems/ipo/) |
| 480 | [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) |

---

## Chapter exit criteria

- [ ] Top-K with heap and with buckets
- [ ] Median data stream two-heap
- [ ] Merge K lists
- [ ] Task Scheduler counting math or heap
