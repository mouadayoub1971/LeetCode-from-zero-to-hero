# Chapter 17 — Math & Geometry

> Number theory basics, matrix walks, coordinate tricks.

## Notion

### Number theory toolkit

```python
# GCD / LCM
import math
math.gcd(a, b)
lcm = a // math.gcd(a, b) * b

# Primality (trial)
def is_prime(n):
    if n < 2: return False
    if n % 2 == 0: return n == 2
    i = 3
    while i * i <= n:
        if n % i == 0: return False
        i += 2
    return True

# Sieve
def sieve(n):
    p = [True]*(n+1)
    p[0]=p[1]=False
    for i in range(2, int(n**0.5)+1):
        if p[i]:
            for j in range(i*i, n+1, i):
                p[j]=False
    return p

# Fast pow mod
def modpow(a, e, mod):
    r = 1
    while e:
        if e & 1: r = r * a % mod
        a = a * a % mod
        e >>= 1
    return r
```

### Modular arithmetic

- `(a + b) % m = ((a%m) + (b%m)) % m`
- Negative: `((a % m) + m) % m`
- Division mod prime: multiply by modular inverse

### Geometry / matrix

#### Rotate matrix 90° clockwise

```python
# transpose then reverse each row
for i in range(n):
    for j in range(i+1, n):
        m[i][j], m[j][i] = m[j][i], m[i][j]
for row in m:
    row.reverse()
```

#### Spiral order

Maintain bounds `top, bottom, left, right`; peel layers.

#### Set matrix zeroes

Use first row/col as markers (O(1) space).

#### Robot / directions

```python
dirs = [(0,1), (1,0), (0,-1), (-1,0)]  # R, D, L, U
di = 0
# turn right: di = (di+1)%4
# turn left:  di = (di+3)%4
```

### Happy number / digital root cycles

Floyd cycle or set of seen sums of squares.

### Pow(x, n)

Binary exponentiation; handle negative n as `1/pow(x,-n)`.

### Random / sampling

Reservoir sampling when stream size unknown (Ch. related).

### Coordinate geometry

- Slope as reduced fraction `(dy//g, dx//g)` with sign normalized
- Manhattan: `|x1-x2| + |y1-y2|`
- Euclidean squared to avoid floats

### Overflow

In C++/Java use `long`; check mid as `lo + (hi-lo)/2`.

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 202 | [Happy Number](https://leetcode.com/problems/happy-number/) |
| 66 | [Plus One](https://leetcode.com/problems/plus-one/) |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) |
| 412 | [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/) |
| 168 | [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) |
| 171 | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) |
| 263 | [Ugly Number](https://leetcode.com/problems/ugly-number/) |
| 326 | [Power of Three](https://leetcode.com/problems/power-of-three/) |
| 367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) |

### Medium

| # | Problem |
|---|---------|
| 50 | [Pow(x, n)](https://leetcode.com/problems/powx-n/) |
| 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) |
| 43 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) |
| 48 | [Rotate Image](https://leetcode.com/problems/rotate-image/) |
| 54 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) |
| 59 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) |
| 73 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) |
| 204 | [Count Primes](https://leetcode.com/problems/count-primes/) |
| 172 | [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/) |
| 166 | [Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/) |
| 29 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) |
| 8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) |
| 149 | [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/) |
| 2013 | [Detect Squares](https://leetcode.com/problems/detect-squares/) |
| 223 | [Rectangle Area](https://leetcode.com/problems/rectangle-area/) |
| 939 | [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/) |
| 335 | [Self Crossing](https://leetcode.com/problems/self-crossing/) |

### Hard

| # | Problem |
|---|---------|
| 65 | [Valid Number](https://leetcode.com/problems/valid-number/) |
| 273 | [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) |
| 335 | Self Crossing |
| 391 | [Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/) |

---

## Chapter exit criteria

- [ ] Rotate matrix + spiral
- [ ] Binary exponentiation
- [ ] GCD applications (including slope reduce)
- [ ] Handle overflow / negative mods carefully
