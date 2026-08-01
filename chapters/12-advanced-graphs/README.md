# Chapter 12 — Advanced Graphs

> Beyond plain DFS/BFS: MST, articulation ideas, Euler, grid tricks, state graphs.

## Notion

### 1. Minimum Spanning Tree (MST)

Connect all nodes with min total edge weight, no cycles.

**Kruskal:** sort edges, add if Union-Find doesn't connect same component.  
**Prim:** grow tree from a node using min-heap of edges.

```python
# Kruskal sketch
edges.sort(key=lambda e: e[2])  # (u,v,w)
uf = UnionFind(n)
ans = 0
for u, v, w in edges:
    if uf.union(u, v):
        ans += w
```

### 2. Critical connections (bridges)

Tarjan / discovery time + low-link values. Edge u–v is a bridge if `low[v] > disc[u]`.

### 3. Strongly connected components (directed)

Kosaraju (2 DFS) or Tarjan. Rare on LC but good knowledge.

### 4. Euler path / circuit

Hierholzer’s algorithm: visit unused edges, post-order build path.  
LC: Reconstruct Itinerary.

### 5. State-space graphs

Node = (position, mask/keys/fuel). Edges = valid moves. BFS/Dijkstra on expanded state.

Examples:
- Shortest path with k obstacle eliminations → state `(i, j, k_left)`
- Shortest path to collect all keys → `(i, j, key_bitmask)`

### 6. Implicit graphs

- Word ladder: words differing by 1 letter
- Lock open: 4 dials ±1
- Jump game II as BFS on indices

### 7. Graph modeling tricks

| Real problem | Graph model |
|--------------|-------------|
| Courses with prereqs | Directed edges prereq → course |
| Accounts merge emails | UF on emails |
| Min cost connect points | Complete graph + MST |
| Cheapest flights within k stops | Bellman / modified Dijkstra |
| Swim in rising water | Binary search + DFS or Dijkstra |

### 8. Prim on grid (min cost to connect)

Treat cells or points as nodes; push neighbor edges into heap.

### Swim in Rising Water (Dijkstra idea)

```python
# min-heap of (max_height_so_far, i, j)
# answer is max edge on the path minimized
```

---

## Associated LeetCode problems

### Medium

| # | Problem | Topic |
|---|---------|-------|
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) | MST |
| 1135 | Connecting Cities With Minimum Cost (Premium) | MST |
| 684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection/) | UF cycle |
| 685 | [Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/) | Directed |
| 990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) | UF |
| 721 | [Accounts Merge](https://leetcode.com/problems/accounts-merge/) | UF |
| 332 | [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) | Euler |
| 787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Bellman |
| 743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | Dijkstra |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) | Dijkstra / BS |
| 778 | [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) | Dijkstra / BS |
| 269 | Alien Dictionary (Premium) | Topo |
| 310 | [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) | Peel leaves |
| 802 | [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/) | Reverse / color |
| 1466 | [Reorder Routes to Make All Paths Lead to the City Zero](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/) | DFS |

### Hard

| # | Problem | Topic |
|---|---------|-------|
| 1192 | [Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/) | Bridges |
| 1489 | [Find Critical and Pseudo-Critical Edges in MST](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/) | MST |
| 2093 | Minimum Cost to Reach City With Discounts (Premium) | State Dijkstra |
| 864 | [Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/) | State BFS |
| 1293 | Shortest Path with Obstacles Elimination | State BFS |
| 815 | [Bus Routes](https://leetcode.com/problems/bus-routes/) | BFS modeling |
| 1263 | [Minimum Moves to Move a Box...](https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/) | Complex BFS |

---

## Chapter exit criteria

- [ ] Kruskal MST with UF
- [ ] Model at least one state-space BFS
- [ ] Reconstruct Itinerary (Hierholzer)
- [ ] Network Delay Time (Dijkstra)
- [ ] Explain bridge condition intuitively
