# Chapter 22 — String Algorithms

> Beyond sliding window: pattern matching, hashing, parsing.

## Notion

### 1. Rolling hash (Rabin-Karp)

```python
# hash of window length L
# h = (h * BASE + add - remove * BASE^L) % MOD
# use large prime MOD; optional double hash to reduce collisions
```

Use for: repeated substring, longest dup substring, string matching.

### 2. KMP (Knuth-Morris-Pratt)

Build LPS (longest proper prefix which is suffix) array; match in O(n+m).

```python
def lps(p):
    n = len(p)
    pi = [0]*n
    j = 0
    for i in range(1, n):
        while j and p[i] != p[j]:
            j = pi[j-1]
        if p[i] == p[j]:
            j += 1
            pi[i] = j
    return pi
```

### 3. Z-algorithm

`Z[i]` = longest substring from i matching prefix. O(n).

### 4. Manacher’s algorithm

Longest palindromic substring in O(n). Expand-around-center is O(n²) and usually enough for interviews.

### 5. Trie for strings (Ch.08)

Prefix problems, word search II.

### 6. Parsing / state machines

atoi, valid number, decode string, calculator — walk with index + states.

### 7. Suffix array / SAM

Rare on LC interviews; useful for contests (longest common substring of many).

### 8. String DP

LCS, edit distance, palindrome partition, regex — see Ch.14.

### Interview defaults

| Problem | First tool |
|---------|------------|
| Pattern in text | KMP or built-in / rolling hash |
| Longest palindrome substr | Expand center |
| Anagrams | Count / sort |
| Repeated pattern | KMP lps or `s in (s+s)[1:-1]` |
| Decode / calculator | Stack |

### Check if string is rotation

`len equal and s2 in s1+s1`.

### Count-sort strings

If alphabet small (lowercase 26), counting beats sort for anagram keys.

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 28 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | KMP |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) |
| 125 | Valid Palindrome |
| 242 | Valid Anagram |
| 383 | [Ransom Note](https://leetcode.com/problems/ransom-note/) |
| 387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) |
| 415 | [Add Strings](https://leetcode.com/problems/add-strings/) |
| 459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/) |
| 680 | [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) |

### Medium

| # | Problem |
|---|---------|
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) |
| 3 | Longest Substring Without Repeating |
| 49 | Group Anagrams |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) |
| 165 | [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/) |
| 394 | [Decode String](https://leetcode.com/problems/decode-string/) |
| 443 | [String Compression](https://leetcode.com/problems/string-compression/) |
| 6 | [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/) |
| 12 / 13 | Integer ↔ Roman |
| 8 | atoi |
| 71 | Simplify Path |
| 468 | [Validate IP Address](https://leetcode.com/problems/validate-ip-address/) |
| 647 | Palindromic Substrings |
| 187 | Repeated DNA Sequences |
| 686 | [Repeated String Match](https://leetcode.com/problems/repeated-string-match/) |
| 791 | [Custom Sort String](https://leetcode.com/problems/custom-sort-string/) |
| 890 | [Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/) |

### Hard

| # | Problem |
|---|---------|
| 76 | Minimum Window Substring |
| 30 | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) |
| 214 | [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) | KMP |
| 10 | Regex Matching |
| 44 | Wildcard Matching |
| 273 | Integer to English Words |
| 65 | Valid Number |
| 1044 | [Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/) | Binary search + rolling hash |
| 32 | Longest Valid Parentheses |

---

## Chapter exit criteria

- [ ] Expand-around-center palindrome
- [ ] Build LPS / explain KMP idea
- [ ] Rolling hash window update formula
- [ ] Decode string with stack
