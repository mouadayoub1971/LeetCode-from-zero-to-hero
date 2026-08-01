# Chapter 11 — Graphs (DFS & BFS)

> Nodes + edges. Connectivity, islands, shortest unweighted path, bipartite.

## Notion

### Representations

```python
# adjacency list (default choice)
graph = {0: [1, 2], 1: [0, 3], ...}
# or
from collections import defaultdict
g = defaultdict(list)
for u, v in edges:
    g[u].append(v)
    g[v].append(u)  # if undirected
```

Grid = implicit graph: 4-dir or 8-dir neighbors.

### DFS recursive

```python
def dfs(node, visited, g):
    visited.add(node)
    for nei in g[node]:
        if nei not in visited:
            dfs(nei, visited, g)
```

### DFS iterative

```python
def dfs_iter(start, g):
    st, visited = [start], set()
    while st:
        node = st.pop()
        if node in visited:
            continue
        visited.add(node)
        for nei in g[node]:
            st.append(nei)
```

### BFS (shortest path in unweighted graph)

```python
from collections import deque

def bfs(start, g):
    q = deque([start])
    dist = {start: 0}
    while q:
        node = q.popleft()
        for nei in g[node]:
            if nei not in dist:
                dist[nei] = dist[node] + 1
                q.append(nei)
    return dist
```

### Number of islands (flood fill)

```python
def numIslands(grid):
    if not grid: return 0
    m, n = len(grid), len(grid[0])
    def dfs(i, j):
        if not (0 <= i < m and 0 <= j < n) or grid[i][j] != '1':
            return
        grid[i][j] = '0'
        for di, dj in ((1,0),(-1,0),(0,1),(0,-1)):
            dfs(i+di, j+dj)
    count = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '1':
                count += 1
                dfs(i, j)
    return count
```

### Clone graph

```python
def cloneGraph(node):
    if not node: return None
    mp = {}
    def dfs(n):
        if n in mp: return mp[n]
        copy = Node(n.val)
        mp[n] = copy
        for nei in n.neighbors:
            copy.neighbors.append(dfs(nei))
        return copy
    return dfs(node)
```

### Bipartite check (2-color)

```python
def isBipartite(graph):
    color = {}
    for start in range(len(graph)):
        if start in color: continue
        color[start] = 0
        q = deque([start])
        while q:
            u = q.popleft()
            for v in graph[u]:
                if v not in color:
                    color[v] = color[u] ^ 1
                    q.append(v)
                elif color[v] == color[u]:
                    return False
    return True
```

### Connected components

Run DFS/BFS from every unvisited node; each start = new component. Or Union-Find (Ch.19).

### Cycle detection

- **Undirected:** DFS parent check / Union-Find
- **Directed:** 3-color DFS (white/gray/black) or topo sort failure

### Multi-source BFS

Push **all** sources into queue first (rotting oranges, 01-matrix).

### Time complexity

O(V + E) for adjacency list DFS/BFS.

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 733 | [Flood Fill](https://leetcode.com/problems/flood-fill/) |
| 463 | [Island Perimeter](https://leetcode.com/problems/island-perimeter/) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/) |
| 997 | [Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/) |

### Medium (must)

| # | Problem | Pattern |
|---|---------|---------|
| 200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | Flood fill |
| 133 | [Clone Graph](https://leetcode.com/problems/clone-graph/) | DFS copy |
| 695 | [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | Flood |
| 417 | [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) | Multi DFS |
| 130 | [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) | Border DFS |
| 994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | Multi BFS |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | BFS |
| 542 | [01 Matrix](https://leetcode.com/problems/01-matrix/) | Multi BFS |
| 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | Cycle / topo |
| 210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | Topo |
| 261 | Graph Valid Tree (Premium) | n-1 edges + connected |
| 323 | Number of Connected Components (Premium) | Components |
| 785 | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) | 2-color |
| 286 | Walls and Gates (Premium) | Multi BFS |
| 752 | [Open the Lock](https://leetcode.com/problems/open-the-lock/) | BFS state |
| 127 | [Word Ladder](https://leetcode.com/problems/word-ladder/) | BFS |
| 399 | [Evaluate Division](https://leetcode.com/problems/evaluate-division/) | Weighted DFS |
| 841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/) | DFS |

### Hard

| # | Problem |
|---|---------|
| 127 | Word Ladder (borderline) |
| 126 | [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) |
| 1293 | [Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) |
| 847 | [Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) |

---

## Chapter exit criteria

- [ ] Islands / max area cold
- [ ] Multi-source BFS (oranges)
- [ ] Detect cycle directed + undirected
- [ ] Bipartite coloring
- [ ] Clone graph with map
