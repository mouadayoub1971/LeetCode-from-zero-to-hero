# Chapter 08 — Tries (Prefix Trees)

> Tree of characters for prefix queries in O(length).

## Notion

A Trie stores strings by sharing prefixes. Each edge is a character; a node marks “word ends here”.

```
      root
     /    \
    a      b
   /        \
  p          a
 /            \
p*             t*
```

### Node structure

```python
class Node:
    def __init__(self):
        self.children = {}  # or [None]*26 for lowercase
        self.end = False

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = Node()
            cur = cur.children[c]
        cur.end = True

    def search(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return cur.end

    def startsWith(self, prefix):
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return True
```

### When to use

- Autocomplete / prefix matching
- Word search in board (combine with DFS)
- Replace words with shortest root
- XOR max pair (bit trie)
- Count distinct substrings (sometimes)

### Word Search II skeleton

```python
def findWords(board, words):
    trie = Trie()
    for w in words:
        trie.insert(w)
    res, m, n = set(), len(board), len(board[0])

    def dfs(i, j, node, path):
        if node.end:
            res.add(path)
            # optional: node.end = False to dedupe
        if not (0 <= i < m and 0 <= j < n):
            return
        c = board[i][j]
        if c == '#' or c not in node.children:
            return
        board[i][j] = '#'
        nxt = node.children[c]
        for di, dj in ((1,0),(-1,0),(0,1),(0,-1)):
            dfs(i+di, j+dj, nxt, path + c)
        board[i][j] = c

    for i in range(m):
        for j in range(n):
            dfs(i, j, trie.root, "")
    return list(res)
```

### Bit Trie (max XOR)

```python
# insert numbers bit by bit (MSB first), query opposite bits greedily
```

### Complexity

- Insert/search: O(L) per word length L
- Space: O(total characters) worst case

### Array[26] vs dict

- Fixed lowercase alphabet → `list` of 26 is faster
- Unicode / large alphabet → `dict`

---

## Associated LeetCode problems

### Medium

| # | Problem |
|---|---------|
| 208 | [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) |
| 211 | [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) |
| 648 | [Replace Words](https://leetcode.com/problems/replace-words/) |
| 677 | [Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/) |
| 720 | [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/) |
| 1268 | [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) |
| 421 | [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) |

### Hard

| # | Problem |
|---|---------|
| 212 | [Word Search II](https://leetcode.com/problems/word-search-ii/) |
| 336 | [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/) |
| 1032 | [Stream of Characters](https://leetcode.com/problems/stream-of-characters/) |

### Related (without full trie)

| # | Problem |
|---|---------|
| 79 | [Word Search](https://leetcode.com/problems/word-search/) | DFS backtrack |
| 14 | Longest Common Prefix | Simple scan first |

---

## Chapter exit criteria

- [ ] Implement Trie insert/search/startsWith
- [ ] Wildcard search ('.') DFS on trie
- [ ] Word Search II with trie pruning
- [ ] Know space/time tradeoffs vs hash set of all prefixes
