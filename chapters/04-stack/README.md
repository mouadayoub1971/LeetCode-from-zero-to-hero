# Chapter 04 — Stack

> LIFO structure for matching, nested structure, undo, and evaluation.

## Notion

Stack = push / pop / peek from the **top only**. Last in, first out.

### When to use

- Matching brackets / nested structures
- Parse expressions (RPN, calculator)
- “Previous / next smaller or greater” (→ monotonic, Ch.23)
- DFS iterative
- Simulate recursion
- Path simplification (`/a/./b/../c`)

### Pattern A — Valid parentheses

```python
def isValid(s):
    pairs = {')': '(', ']': '[', '}': '{'}
    st = []
    for c in s:
        if c in '([{':
            st.append(c)
        else:
            if not st or st[-1] != pairs[c]:
                return False
            st.pop()
    return not st
```

### Pattern B — Daily temperatures (monotonic preview)

```python
def dailyTemperatures(temps):
    n = len(temps)
    ans = [0] * n
    st = []  # indices, temps increasing upward? store decreasing
    for i, t in enumerate(temps):
        while st and temps[st[-1]] < t:
            j = st.pop()
            ans[j] = i - j
        st.append(i)
    return ans
```

### Pattern C — Evaluate RPN

```python
def evalRPN(tokens):
    st = []
    for t in tokens:
        if t not in '+-*/':
            st.append(int(t))
        else:
            b, a = st.pop(), st.pop()
            if t == '+': st.append(a + b)
            elif t == '-': st.append(a - b)
            elif t == '*': st.append(a * b)
            else: st.append(int(a / b))  # trunc toward 0
    return st[0]
```

### Pattern D — Min stack

```python
class MinStack:
    def __init__(self):
        self.st = []      # (val, current_min)

    def push(self, val):
        m = val if not self.st else min(val, self.st[-1][1])
        self.st.append((val, m))

    def pop(self):
        self.st.pop()

    def top(self):
        return self.st[-1][0]

    def getMin(self):
        return self.st[-1][1]
```

### Pattern E — Simplify path

```python
def simplifyPath(path):
    st = []
    for part in path.split('/'):
        if part == '' or part == '.':
            continue
        if part == '..':
            if st: st.pop()
        else:
            st.append(part)
    return '/' + '/'.join(st)
```

### Stack vs recursion

Any DFS recursion can become an explicit stack. Prefer recursion when depth is safe; stack when you need control or depth is large.

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) |
| 155 | [Min Stack](https://leetcode.com/problems/min-stack/) |
| 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) |
| 225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) |
| 1047 | [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) |
| 682 | [Baseball Game](https://leetcode.com/problems/baseball-game/) |
| 844 | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/) |

### Medium

| # | Problem |
|---|---------|
| 150 | [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | Backtracking + stack idea |
| 739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) |
| 853 | [Car Fleet](https://leetcode.com/problems/car-fleet/) |
| 71 | [Simplify Path](https://leetcode.com/problems/simplify-path/) |
| 394 | [Decode String](https://leetcode.com/problems/decode-string/) |
| 735 | [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) |
| 946 | [Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/) |
| 456 | [132 Pattern](https://leetcode.com/problems/132-pattern/) |
| 402 | [Remove K Digits](https://leetcode.com/problems/remove-k-digits/) |

### Hard

| # | Problem |
|---|---------|
| 84 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) |
| 85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) |
| 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) |
| 224 | [Basic Calculator](https://leetcode.com/problems/basic-calculator/) |
| 772 | Basic Calculator III (Premium) |

---

## Chapter exit criteria

- [ ] Valid Parentheses + Min Stack cold
- [ ] Daily Temperatures with monotonic stack
- [ ] Decode String nested
- [ ] Know when stack beats other structures
