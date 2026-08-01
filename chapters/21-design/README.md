# Chapter 21 — Design Problems

> Combine data structures to hit required complexities. System-design lite.

## Notion

Design problems ask you to implement a class with methods under time bounds.

### Process

1. List operations + required complexity  
2. Pick structures that support those ops  
3. Often combine **hash map + linked list / heap / set**  
4. Watch consistency when one structure updates  

### Classic: LRU Cache

Need: `get` / `put` in O(1).

```
HashMap: key → node
Doubly Linked List: head (MRU) ... tail (LRU)
```

On get: move node to head.  
On put: insert at head; if over capacity, evict tail.

### LFU Cache

Map key→node, freq→DLL of keys, track min_freq.

### Min Stack

Stack of (val, min_so_far) — O(1) getMin.

### Queue with stacks / Stack with queues

Two stacks for queue amortization.

### RandomizedSet

```
list of values + map value→index
remove: swap with last, pop — O(1)
```

### Twitter / Feed

User map, follow graph, heap merge of recent tweets.

### File system / Trie design

Path split + trie or nested dicts.

### Iterator design (BST iterator)

Controlled inorder stack — O(h) space, amortized O(1) next.

### Snapshot array / versioning

List of (snap_id, val) per index; binary search.

### Principles

| Need | Structure |
|------|-----------|
| O(1) avg lookup | HashMap |
| O(1) insert/delete ends | Deque / DLL |
| Order by key | TreeMap / SortedList |
| Order by priority | Heap (lazy delete) |
| Prefix | Trie |
| Undo | Stack |
| Range | SegTree / policy |

### Lazy deletion

Heaps don't support arbitrary delete easily → push new, skip stale on pop via map of valid versions.

---

## Associated LeetCode problems

### Easy / Medium

| # | Problem |
|---|---------|
| 155 | [Min Stack](https://leetcode.com/problems/min-stack/) |
| 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) |
| 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) |
| 705 | [Design HashSet](https://leetcode.com/problems/design-hashset/) |
| 706 | [Design HashMap](https://leetcode.com/problems/design-hashmap/) |
| 384 | [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/) |
| 380 | [Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) |
| 146 | [LRU Cache](https://leetcode.com/problems/lru-cache/) |
| 208 | [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/) |
| 211 | [Design Add and Search Words](https://leetcode.com/problems/design-add-and-search-words-data-structure/) |
| 173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) |
| 341 | [Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/) |
| 284 | [Peeking Iterator](https://leetcode.com/problems/peeking-iterator/) |
| 362 | Design Hit Counter (Premium) |
| 359 | Logger Rate Limiter (Premium) |
| 346 | Moving Average from Data Stream (Premium) |
| 622 | [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/) |
| 641 | [Design Circular Deque](https://leetcode.com/problems/design-circular-deque/) |
| 1396 | [Design Underground System](https://leetcode.com/problems/design-underground-system/) |
| 1472 | [Design Browser History](https://leetcode.com/problems/design-browser-history/) |
| 901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span/) |
| 1146 | [Snapshot Array](https://leetcode.com/problems/snapshot-array/) |
| 355 | [Design Twitter](https://leetcode.com/problems/design-twitter/) |
| 729 | [My Calendar I](https://leetcode.com/problems/my-calendar-i/) |
| 981 | [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/) |
| 535 | [Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/) |

### Hard

| # | Problem |
|---|---------|
| 460 | [LFU Cache](https://leetcode.com/problems/lfu-cache/) |
| 432 | [All O`one Data Structure](https://leetcode.com/problems/all-oone-data-structure/) |
| 716 | Max Stack (Premium) |
| 295 | [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) |
| 588 | Design In-Memory File System (Premium) |
| 631 | Design Excel Sum Formula (Premium) |

---

## Chapter exit criteria

- [ ] LRU Cache full implementation
- [ ] Insert Delete GetRandom O(1)
- [ ] Time-based KV (binary search versions)
- [ ] Explain structure combo + complexities before coding
