# Chapter 07 — Trees (Binary Trees & BST)

> Hierarchical DFS/BFS. Huge fraction of Medium interviews.

## Notion

Binary tree node: `val`, `left`, `right`.

### Traversals

| Order | Sequence | Use |
|-------|----------|-----|
| Preorder | root → L → R | Copy tree, serialize prefix |
| Inorder | L → root → R | BST → sorted |
| Postorder | L → R → root | Delete, compute from children |
| Level-order | BFS by level | Level problems |

```python
def preorder(root):
    if not root: return
    visit(root)
    preorder(root.left)
    preorder(root.right)

def inorder(root):
    if not root: return
    inorder(root.left)
    visit(root)
    inorder(root.right)

def postorder(root):
    if not root: return
    postorder(root.left)
    postorder(root.right)
    visit(root)

from collections import deque
def level_order(root):
    if not root: return []
    q, res = deque([root]), []
    while q:
        level = []
        for _ in range(len(q)):
            node = q.popleft()
            level.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        res.append(level)
    return res
```

### DFS return-value pattern (most powerful)

```python
def maxDepth(root):
    if not root:
        return 0
    return 1 + max(maxDepth(root.left), maxDepth(root.right))

def isBalanced(root):
    def height(n):
        if not n: return 0
        lh, rh = height(n.left), height(n.right)
        if lh < 0 or rh < 0 or abs(lh - rh) > 1:
            return -1  # sentinel = unbalanced
        return 1 + max(lh, rh)
    return height(root) >= 0
```

### Path / global answer pattern

```python
def diameterOfBinaryTree(root):
    best = 0
    def depth(n):
        nonlocal best
        if not n: return 0
        L, R = depth(n.left), depth(n.right)
        best = max(best, L + R)  # path through n
        return 1 + max(L, R)
    depth(root)
    return best
```

### BST property

For every node: all left < node < all right (or ≤ depending on problem).

```python
def searchBST(root, val):
    while root and root.val != val:
        root = root.left if val < root.val else root.right
    return root

def isValidBST(root):
    def ok(n, lo, hi):
        if not n: return True
        if not (lo < n.val < hi): return False
        return ok(n.left, lo, n.val) and ok(n.right, n.val, hi)
    return ok(root, float('-inf'), float('inf'))
```

### LCA (Binary Tree)

```python
def lowestCommonAncestor(root, p, q):
    if not root or root is p or root is q:
        return root
    L = lowestCommonAncestor(root.left, p, q)
    R = lowestCommonAncestor(root.right, p, q)
    if L and R: return root
    return L or R
```

### Serialize / deserialize

```python
def serialize(root):
    def dfs(n):
        if not n: return ['#']
        return [str(n.val)] + dfs(n.left) + dfs(n.right)
    return ','.join(dfs(root))
```

### Iterative inorder (kth smallest BST)

```python
def kthSmallest(root, k):
    st = []
    cur = root
    while True:
        while cur:
            st.append(cur)
            cur = cur.left
        cur = st.pop()
        k -= 1
        if k == 0: return cur.val
        cur = cur.right
```

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) |
| 100 | [Same Tree](https://leetcode.com/problems/same-tree/) |
| 226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) |
| 543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) |
| 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) |
| 572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) |
| 112 | [Path Sum](https://leetcode.com/problems/path-sum/) |
| 101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) |
| 144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) |
| 94 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) |
| 108 | [Convert Sorted Array to BST](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) |
| 235 | [LCA of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) |

### Medium

| # | Problem |
|---|---------|
| 102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) |
| 98 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) |
| 230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) |
| 236 | [LCA of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) |
| 199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) |
| 105 | [Construct Binary Tree from Preorder and Inorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) |
| 106 | [Construct from Inorder and Postorder](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |
| 124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | Hard-ish |
| 114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) |
| 437 | [Path Sum III](https://leetcode.com/problems/path-sum-iii/) |
| 662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) |
| 863 | [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) |
| 297 | [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) |

### Hard

| # | Problem |
|---|---------|
| 124 | Binary Tree Maximum Path Sum |
| 297 | Serialize and Deserialize |
| 968 | [Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/) |
| 99 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) |

---

## Chapter exit criteria

- [ ] All 4 traversals recursive + BFS levels
- [ ] Diameter / max path sum pattern (global + return)
- [ ] Validate BST with bounds
- [ ] LCA binary tree
- [ ] Build tree from preorder+inorder
