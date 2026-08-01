# Chapter 06 — Linked List

> Pointer gymnastics: reverse, merge, cycle, slow-fast.

## Notion

Node = `val` + `next` (+ `prev` if doubly linked). No O(1) index — only sequential access.

### Core skills (must be automatic)

1. Reverse a list (iterative)
2. Find middle (slow/fast)
3. Detect cycle (Floyd)
4. Merge two sorted lists
5. Dummy head technique
6. Remove nth from end
7. Deep copy with random pointer

### Template — reverse iterative

```python
def reverseList(head):
    prev, cur = None, head
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    return prev
```

### Template — dummy head

```python
def removeElements(head, val):
    dummy = ListNode(0, head)
    cur = dummy
    while cur.next:
        if cur.next.val == val:
            cur.next = cur.next.next
        else:
            cur = cur.next
    return dummy.next
```

Dummy avoids special-casing empty head / deleting head.

### Template — slow & fast (middle)

```python
def middleNode(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow  # second middle if even
```

### Template — cycle detect + entrance

```python
def detectCycle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            slow = head
            while slow is not fast:
                slow = slow.next
                fast = fast.next
            return slow
    return None
```

### Template — merge two sorted

```python
def mergeTwoLists(a, b):
    dummy = ListNode()
    t = dummy
    while a and b:
        if a.val <= b.val:
            t.next, a = a, a.next
        else:
            t.next, b = b, b.next
        t = t.next
    t.next = a or b
    return dummy.next
```

### Template — reorder list (common combo)

1. Find middle, split
2. Reverse second half
3. Interleave merge

### Complexity

Almost always O(n) time, O(1) extra space (iterative). Recursion uses O(n) stack.

### Common bugs

- Losing reference to `next` before rewiring
- Off-by-one on slow/fast for even length
- Forgetting `dummy.next` return
- Infinite loop if cycle not handled

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) |
| 21 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) |
| 141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) |
| 234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) |
| 876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) |
| 83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) |
| 203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) |
| 160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) |

### Medium

| # | Problem |
|---|---------|
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |
| 143 | [Reorder List](https://leetcode.com/problems/reorder-list/) |
| 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) |
| 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) |
| 138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) |
| 61 | [Rotate List](https://leetcode.com/problems/rotate-list/) |
| 86 | [Partition List](https://leetcode.com/problems/partition-list/) |
| 24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) |
| 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) |
| 146 | [LRU Cache](https://leetcode.com/problems/lru-cache/) | Design + DLL |
| 430 | [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) |

### Hard

| # | Problem |
|---|---------|
| 25 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | Heap |
| 460 | [LFU Cache](https://leetcode.com/problems/lfu-cache/) |

---

## Chapter exit criteria

- [ ] Reverse list iterative + recursive
- [ ] Cycle detect + find entrance
- [ ] Reorder list full pipeline
- [ ] Reverse k-group
