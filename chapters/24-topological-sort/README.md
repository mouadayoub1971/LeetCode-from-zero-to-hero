# Chapter 24 — Topological Sort

> Order nodes in a DAG so every edge u→v has u before v. Dependencies.

## Notion

Works **only on Directed Acyclic Graphs**. Cycle ⇒ no topo order.

### Kahn’s algorithm (BFS)

```python
from collections import deque, defaultdict

def topo_kahn(n, edges):
    g = defaultdict(list)
    indeg = [0] * n
    for u, v in edges:  # u must come before v
        g[u].append(v)
        indeg[v] += 1
    q = deque([i for i in range(n) if indeg[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in g[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    return order if len(order) == n else []  # empty → cycle
```

### DFS post-order method

```python
def topo_dfs(n, edges):
    g = defaultdict(list)
    for u, v in edges:
        g[u].append(v)
    WHITE, GRAY, BLACK = 0, 1, 2
    color = [WHITE] * n
    order = []
    cycle = False

    def dfs(u):
        nonlocal cycle
        if cycle: return
        color[u] = GRAY
        for v in g[u]:
            if color[v] == GRAY:
                cycle = True
                return
            if color[v] == WHITE:
                dfs(v)
        color[u] = BLACK
        order.append(u)

    for i in range(n):
        if color[i] == WHITE:
            dfs(i)
    if cycle:
        return []
    order.reverse()
    return order
```

### Course Schedule mapping

- Courses `0..n-1`
- Edge `prereq → course` (or reverse carefully)
- Can finish ⇔ topo exists (no cycle)
- Order = Course Schedule II

### Alien dictionary

1. Build graph from adjacent word pairs (first differing char)  
2. Detect invalid prefix case (`apple` before `app`)  
3. Topo sort letters  

### Parallel courses / levels

Kahn by layers: each BFS layer = one semester; count layers.

### Priority topo (lex smallest order)

Use **min-heap** instead of queue when popping zero-indegree nodes.

### Complexity

O(V + E).

---

## Associated LeetCode problems

### Medium

| # | Problem |
|---|---------|
| 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/) |
| 210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) |
| 269 | Alien Dictionary (Premium) |
| 310 | [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) | Peel leaves (undirected) |
| 1136 | Parallel Courses (Premium) |
| 1857 | [Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/) |
| 1462 | [Course Schedule IV](https://leetcode.com/problems/course-schedule-iv/) |
| 802 | [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/) |
| 2115 | [Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/) |
| 851 | [Loud and Rich](https://leetcode.com/problems/loud-and-rich/) |
| 1203 | [Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/) |
| 444 | Sequence Reconstruction (Premium) |
| 2050 | [Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/) |

### Hard

| # | Problem |
|---|---------|
| 269 | Alien Dictionary |
| 1203 | Sort Items by Groups |
| 1857 | Largest Color Value |
| 329 | Longest Increasing Path (DFS memo, DAG idea) |

---

## Chapter exit criteria

- [ ] Kahn + DFS topo both from memory
- [ ] Course Schedule I & II
- [ ] Detect cycle via both methods
- [ ] Lexicographically smallest topo with heap
