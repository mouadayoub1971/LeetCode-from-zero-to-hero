# Chapter 26 — Meta-Patterns & Interview Mastery

> The glue chapter. Pattern recognition under pressure + communication.

## Notion: problem → pattern map

When you read a problem, run this decision tree:

```
1. Input structure?
   array/string → hashing, two pointers, window, stack, binary search, DP
   linked list → reverse, slow-fast, dummy
   tree → DFS return value, BFS levels, BST property
   graph → DFS/BFS, UF, topo, shortest path
   matrix → DFS flood, BFS, DP grid, rotate

2. Ask keywords?
   "subarray/substring contiguous" → window / prefix / Kadane
   "subsequence" → DP / two pointers
   "kth" → heap / quickselect
   "shortest unweighted" → BFS
   "minimum cost path weighted" → Dijkstra
   "all possibilities" → backtracking
   "optimal count/ways" → DP
   "dependencies / order" → topo
   "connected dynamically" → UF
   "prefix words" → trie
   "next greater" → monotonic stack
   "merge intervals" → sort + sweep
   "design O(1)" → hash + DLL/list

3. Constraints?
   n ≤ 20 → bitmask / 2^n
   n ≤ 100 → n³ DP maybe
   n ≤ 1e5 → n or n log n
```

## The 15 patterns that cover ~90% of LC

1. Hash map / set  
2. Two pointers  
3. Sliding window  
4. Prefix sum  
5. Binary search (index + answer)  
6. Stack / monotonic stack  
7. Heap / top-K  
8. Intervals merge & sweep  
9. Linked list pointers  
10. Tree DFS/BFS  
11. Graph DFS/BFS  
12. Backtracking  
13. Dynamic programming (1D/2D)  
14. Greedy  
15. Union-Find / Topo / Trie / Bitmask (specialists)

## Interview communication script

```
1. Restate: "So we get ___, and should return ___. Constraints say n up to ___."
2. Example: walk through given example; add one edge-case example.
3. Brute force: state approach + complexity. "This is too slow because ___."
4. Optimize: "The bottleneck is ___. If I use ___, I can ___."
5. Confirm: "I'll implement ___. Does that sound good?"
6. Code cleanly with meaningful names.
7. Trace one example on the code.
8. Complexity + edge cases aloud.
```

## What interviewers grade

| Signal | Good | Bad |
|--------|------|-----|
| Clarifying questions | Constraints, I/O, edge | Jump into code |
| Structure | Brute → better | Random coding |
| Correctness | Tests edges | Happy path only |
| Complexity awareness | States Big-O accurately | "It's fast" |
| Code quality | Clean, modular | One giant mess |
| Collaboration | Think aloud | Silent 20 minutes |

## Spaced repetition system

Track every problem:

```
| Date | Problem | Pattern | Result | Next review |
```

Results: `Solved clean` / `Solved with hint` / `Failed`.

Review schedule for fails: **1d → 3d → 7d → 30d**.

## Mock interview checklist

- [ ] 45 minutes timer  
- [ ] Speak continuously  
- [ ] No IDE autocomplete if possible  
- [ ] End with complexity  
- [ ] Note one improvement  

## Company-style focus (approx.)

| Focus | Patterns |
|-------|----------|
| Meta / Amazon | Arrays, hashing, trees, graphs, design (LRU) |
| Google | Graphs, DP hard, recursion, correctness |
| Apple | Practical DS, concurrency lite, clarity |
| Startups | Speed + medium patterns |

## Final “graduation” problem set (mixed)

Do these timed (25–35 min each) with zero notes:

1. Two Sum / Group Anagrams  
2. Longest Substring Without Repeating  
3. 3Sum  
4. Binary Search on answer (Koko)  
5. Reverse Linked List + Detect Cycle  
6. Level Order + LCA  
7. Number of Islands + Course Schedule  
8. House Robber + Coin Change  
9. Merge Intervals + Meeting Rooms II  
10. LRU Cache  
11. Word Search / Subsets  
12. Daily Temperatures / Histogram  
13. Network Delay Time  
14. Edit Distance or LCS  
15. Trie implement + Word Search II  

If you clear 12/15 cleanly, you are interview-ready for most mid-level roles.

## How to keep growing after the chapters

1. Blind 75 → NeetCode 150 → company tagged  
2. Contest weekly (Codeforces Div2 A–C / LC weekly) for speed  
3. Re-implement templates monthly in your interview language  
4. Teach a pattern out loud (Feynman technique)  

## Language note for this repo

You already have C++/Java solutions in the root folders. For each chapter problem you solve:

```
chapters/XX-name/solutions/
  problem_name.py   or .cpp / .java
```

Rewrite templates in **your interview language** until muscle memory.

---

## Full curriculum exit criteria

- [ ] All chapters 00–25 exit criteria checked  
- [ ] 150+ problems solved with notes  
- [ ] 10 timed mocks  
- [ ] Can draw the pattern decision tree from memory  
- [ ] LRU, Dijkstra, UF, backtracking, window, DP fib/knapsack/LIS all cold  

**You don’t need every Hard. You need every Medium pattern automatic.**

---

## Quick links back

| Phase | Chapters |
|-------|----------|
| Foundations | [00](../00-complexity-and-mindset/) … [08](../08-tries/) |
| Core | [09](../09-heap-priority-queue/) … [16](../16-intervals/) |
| Advanced | [17](../17-math-and-geometry/) … [25](../25-shortest-path/) |
| Meta | You are here |
