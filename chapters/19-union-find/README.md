# Chapter 19 — Union-Find (Disjoint Set Union)

> Dynamic connectivity: “are a and b in the same component?” in nearly O(1).

## Notion

Maintain a partition of elements into disjoint sets.

### Operations

- `find(x)` → representative (root) of x’s set  
- `union(x, y)` → merge sets of x and y  
- `connected(x, y)` → `find(x) == find(y)`

### Implementation (path compression + union by rank)

```python
class UF:
    def __init__(self, n):
        self.p = list(range(n))
        self.r = [0] * n
        self.components = n

    def find(self, x):
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]  # path compression
            x = self.p[x]
        return x

    def union(self, a, b):
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False  # already connected
        if self.r[ra] < self.r[rb]:
            ra, rb = rb, ra
        self.p[rb] = ra
        if self.r[ra] == self.r[rb]:
            self.r[ra] += 1
        self.components -= 1
        return True
```

**Ackermann inverse** amortized ≈ O(1) per op.

### When to use

- Number of connected components (undirected)
- Detect cycle when adding edges
- Kruskal MST
- Equivalence relations (equations, accounts merge)
- Grid connectivity with dynamic obstacles (sometimes)
- “Earliest time when graph connects”

### Grid mapping

Cell `(i,j)` → id `i * n + j`. Virtual nodes for borders (Surrounded Regions, Swim).

### Variants

- **Union by size** instead of rank; track size for “largest component”
- **Weighted UF** for Evaluate Division ratios
- **Rollback UF** for offline queries (advanced)

### UF vs DFS

| Static graph full traverse | DFS/BFS simpler |
| Dynamic edge additions | UF shines |
| Need path itself | DFS/BFS |

---

## Associated LeetCode problems

### Medium

| # | Problem |
|---|---------|
| 547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) |
| 684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection/) |
| 990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) |
| 721 | [Accounts Merge](https://leetcode.com/problems/accounts-merge/) |
| 1319 | [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) | Kruskal |
| 1101 | The Earliest Moment When Everyone Become Friends (Premium) |
| 1202 | [Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/) |
| 947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) |
| 399 | [Evaluate Division](https://leetcode.com/problems/evaluate-division/) | Weighted |
| 261 | Graph Valid Tree (Premium) |
| 323 | Number of Connected Components (Premium) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/) |
| 1722 | [Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/) |

### Hard

| # | Problem |
|---|---------|
| 685 | [Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/) |
| 1579 | [Remove Max Number of Edges to Keep Graph Fully Traversable](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/) |
| 839 | [Similar String Groups](https://leetcode.com/problems/similar-string-groups/) |
| 803 | [Bricks Falling When Hit](https://leetcode.com/problems/bricks-falling-when-hit/) | Reverse UF |
| 924 | [Minimize Malware Spread](https://leetcode.com/problems/minimize-malware-spread/) |
| 1489 | Critical / Pseudo-Critical Edges MST |

---

## Chapter exit criteria

- [ ] Code UF with path compression + rank from memory
- [ ] Provinces / Redundant Connection
- [ ] Accounts Merge
- [ ] Kruskal using UF
