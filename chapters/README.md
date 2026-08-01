# LeetCode From Zero to Hero — Chapters

A complete, ordered curriculum. If you master every chapter in order, you can solve **any** LeetCode problem by pattern recognition.

## How to use this

1. **Read the notion** in each chapter (`README.md`) until you can explain it out loud.
2. **Implement the templates** from memory (no looking).
3. **Solve the problems** in order: Easy → Medium → Hard.
4. **For each problem**, write:
   - Pattern name
   - Why this pattern
   - Time / space complexity
   - Edge cases
5. **Spaced repetition**: revisit failed problems after 1 day, 3 days, 7 days.

### Daily routine (recommended)

| Phase | Duration | Focus |
|-------|----------|--------|
| Warm-up | 10 min | 1 Easy from a past chapter |
| Learn | 30–40 min | Read notion + code template |
| Practice | 60–90 min | 2–3 problems (1 new, 1 review) |
| Review | 10 min | Write mistakes in a notebook |

**Target:** 1 chapter every 3–7 days depending on difficulty. Full path ≈ 3–6 months.

---

## Roadmap (order matters)

### Phase 1 — Foundations (must be automatic)

| # | Chapter | Why it matters |
|---|---------|----------------|
| 00 | [Complexity & Mindset](./00-complexity-and-mindset/) | Big-O, problem-solving framework |
| 01 | [Arrays & Hashing](./01-arrays-and-hashing/) | ~30% of all LC problems start here |
| 02 | [Two Pointers](./02-two-pointers/) | Sorted arrays, pairs, partitions |
| 03 | [Sliding Window](./03-sliding-window/) | Subarrays / substrings |
| 04 | [Stack](./04-stack/) | Matching, monotonic, undo |
| 05 | [Binary Search](./05-binary-search/) | Log-time on sorted / answer space |
| 06 | [Linked List](./06-linked-list/) | Pointers, cycles, reverse |
| 07 | [Trees](./07-trees/) | DFS/BFS on hierarchies |
| 08 | [Tries](./08-tries/) | Prefix problems |

### Phase 2 — Core Algorithms

| # | Chapter | Why it matters |
|---|---------|----------------|
| 09 | [Heap / Priority Queue](./09-heap-priority-queue/) | Top-K, scheduling |
| 10 | [Backtracking](./10-backtracking/) | Subsets, permutations, constraints |
| 11 | [Graphs DFS/BFS](./11-graphs-dfs-bfs/) | Connectivity, islands, paths |
| 12 | [Advanced Graphs](./12-advanced-graphs/) | MST, bipartite, SCC ideas |
| 13 | [1D Dynamic Programming](./13-1d-dynamic-programming/) | Optimal substructure |
| 14 | [2D Dynamic Programming](./14-2d-dynamic-programming/) | Grids, strings, knapsack |
| 15 | [Greedy](./15-greedy/) | Local optimal → global |
| 16 | [Intervals](./16-intervals/) | Merge, sweep line |

### Phase 3 — Advanced & Interview Edge

| # | Chapter | Why it matters |
|---|---------|----------------|
| 17 | [Math & Geometry](./17-math-and-geometry/) | Number theory, grids |
| 18 | [Bit Manipulation](./18-bit-manipulation/) | Flags, XOR tricks |
| 19 | [Union-Find](./19-union-find/) | Dynamic connectivity |
| 20 | [Segment Tree / Fenwick](./20-segment-fenwick/) | Range queries |
| 21 | [Design](./21-design/) | LRU, systems-style LC |
| 22 | [String Algorithms](./22-string-algorithms/) | KMP, rolling hash |
| 23 | [Monotonic Stack/Queue](./23-monotonic-stack-queue/) | Next greater, window extremes |
| 24 | [Topological Sort](./24-topological-sort/) | Dependencies |
| 25 | [Shortest Path](./25-shortest-path/) | Dijkstra, Bellman-Ford, 0-1 BFS |
| 26 | [Patterns & Interview](./26-patterns-and-interview/) | Meta-patterns, how to interview |

---

## Master pattern checklist

Before claiming “I know LeetCode”, you should recognize and implement these **cold**:

- [ ] Hash map frequency / complement lookup
- [ ] Two pointers (opposite & same direction)
- [ ] Fixed + variable sliding window
- [ ] Prefix sums
- [ ] Binary search on index + on answer
- [ ] Stack for matching / monotonic
- [ ] Linked list reverse, slow-fast, merge
- [ ] Tree DFS (pre/in/post) + BFS levels
- [ ] BST properties
- [ ] Heap top-K / two heaps median
- [ ] Backtracking template (choose / explore / unchoose)
- [ ] Graph DFS/BFS, flood fill
- [ ] Union-Find with path compression
- [ ] Topological sort (Kahn + DFS)
- [ ] Dijkstra with heap
- [ ] 1D DP (climb stairs family)
- [ ] 2D DP (grid paths, LCS, knapsack)
- [ ] Interval merge / sort by start or end
- [ ] Greedy proof intuition
- [ ] Bit masks & XOR
- [ ] Trie insert/search/prefix
- [ ] Monotonic stack (next greater element)
- [ ] Design with correct complexity (LRU)

---

## Difficulty ladder inside each chapter

```
Easy  → learn the pure pattern
Medium → combine 1–2 patterns + edge cases
Hard  → optimize, prove correctness, multi-layer state
```

## Language

Examples use **Python** for clarity. The algorithms are language-agnostic — rewrite every solution in C++/Java if that is your interview language (recommended, given this repo).

## Progress tracker

Copy this into a note and check off chapters:

```
[ ] 00  [ ] 01  [ ] 02  [ ] 03  [ ] 04  [ ] 05  [ ] 06  [ ] 07  [ ] 08
[ ] 09  [ ] 10  [ ] 11  [ ] 12  [ ] 13  [ ] 14  [ ] 15  [ ] 16
[ ] 17  [ ] 18  [ ] 19  [ ] 20  [ ] 21  [ ] 22  [ ] 23  [ ] 24  [ ] 25  [ ] 26
```

**Rule:** a chapter is done only when you can solve its Medium list **without hints** and explain complexity.
