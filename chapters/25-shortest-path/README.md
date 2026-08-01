# Chapter 25 — Shortest Path

> BFS, Dijkstra, Bellman-Ford, 0-1 BFS, Floyd. Weighted graphs.

## Notion

| Graph type | Algorithm | Complexity |
|------------|-----------|------------|
| Unweighted | BFS | O(V+E) |
| Weights 0/1 | 0-1 BFS (deque) | O(V+E) |
| Non-negative weights | Dijkstra | O((V+E) log V) |
| Negative weights, no neg cycle | Bellman-Ford | O(VE) |
| All pairs | Floyd-Warshall | O(V³) |
| ≤ K edges | Bellman relaxed K times / modified Dijkstra | varies |

### BFS unweighted (review)

```python
dist = {start: 0}
q = deque([start])
while q:
    u = q.popleft()
    for v in g[u]:
        if v not in dist:
            dist[v] = dist[u] + 1
            q.append(v)
```

### Dijkstra

```python
import heapq

def dijkstra(n, g, src):
    # g[u] = list of (v, w)
    dist = [float('inf')] * n
    dist[src] = 0
    h = [(0, src)]
    while h:
        d, u = heapq.heappop(h)
        if d > dist[u]:
            continue
        for v, w in g[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(h, (nd, v))
    return dist
```

**Never use Dijkstra with negative edges.**

### Bellman-Ford

```python
def bellman(n, edges, src):
    dist = [float('inf')] * n
    dist[src] = 0
    for _ in range(n - 1):
        updated = False
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break
    # one more pass → negative cycle detection
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            return None  # neg cycle reachable
    return dist
```

### Cheapest flights within K stops

Relax edges K+1 times (Bellman) OR Dijkstra state `(cost, node, stops)`.

### 0-1 BFS

```python
# weight 0 → appendleft, weight 1 → append
dq = deque([src])
dist[src] = 0
while dq:
    u = dq.popleft()
    for v, w in g[u]:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            if w == 0: dq.appendleft(v)
            else: dq.append(v)
```

### Floyd-Warshall

```python
# dist[i][j] init: 0 diag, w edges, inf else
for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

### Grid shortest path

- Unit cost → BFS  
- Effort / height max → Dijkstra or binary search + BFS  
- Obstacles elimination → BFS on state `(i,j,k)`  

### A* (rare LC)

Dijkstra + heuristic; know it exists.

---

## Associated LeetCode problems

### Medium

| # | Problem | Algo |
|---|---------|------|
| 743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | Dijkstra |
| 787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Bellman/Dijkstra |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) | Dijkstra/BS |
| 778 | [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) | Dijkstra/BS |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | BFS |
| 994 | Rotting Oranges | Multi BFS |
| 542 | 01 Matrix | Multi BFS |
| 1514 | [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/) | Dijkstra-like |
| 1368 | [Minimum Cost to Make at Least One Valid Path](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path/) | 0-1 BFS |
| 2290 | [Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/) | 0-1 BFS |
| 1786 | [Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/) | Dijkstra + DP |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) | Dijkstra + count |
| 1334 | [Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) | Floyd/Dijkstra |
| 2699 | [Modify Graph Edge Weights](https://leetcode.com/problems/modify-graph-edge-weights/) | Dijkstra hard |

### Hard

| # | Problem |
|---|---------|
| 1293 | Shortest Path in Grid with Obstacles Elimination |
| 864 | Shortest Path to Get All Keys |
| 847 | Shortest Path Visiting All Nodes |
| 815 | Bus Routes |
| 1263 | Minimum Moves to Move a Box |
| 2093 | Min Cost With Discounts (Premium) |
| 882 | [Reachable Nodes In Subdivided Graph](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/) |

---

## Chapter exit criteria

- [ ] Dijkstra from memory with heap
- [ ] Bellman-Ford + K-stop variant
- [ ] Choose BFS vs Dijkstra vs 0-1 BFS correctly
- [ ] Grid path with state expansion
