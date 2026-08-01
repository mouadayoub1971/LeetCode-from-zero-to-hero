# Chapter 16 — Intervals

> Sort, merge, sweep. Calendar, meetings, coverage.

## Notion

Interval = `[start, end]` (watch inclusive/exclusive!).

### Pattern A — Merge intervals

```python
def merge(intervals):
    intervals.sort()  # by start
    res = []
    for s, e in intervals:
        if not res or res[-1][1] < s:
            res.append([s, e])
        else:
            res[-1][1] = max(res[-1][1], e)
    return res
```

### Pattern B — Insert interval

Merge-like: add all before, merge overlapping with new, add rest.

### Pattern C — Meeting rooms

```python
# can attend all? sort by start, check no overlap with previous end
# min rooms? max concurrent → sort starts & ends or sweep line
def minMeetingRooms(intervals):
    starts = sorted(i[0] for i in intervals)
    ends = sorted(i[1] for i in intervals)
    s = e = 0
    rooms = available = 0
    while s < len(starts):
        if starts[s] < ends[e]:
            if available == 0:
                rooms += 1
            else:
                available -= 1
            s += 1
        else:
            available += 1
            e += 1
    return rooms
```

Heap version: push end times; pop if room free.

### Pattern D — Non-overlapping: min removals

```python
# equivalent to max non-overlapping = activity selection
# sort by end; count keep; removals = n - keep
intervals.sort(key=lambda x: x[1])
keep, end = 0, -inf
for s, e in intervals:
    if s >= end:
        keep += 1
        end = e
return len(intervals) - keep
```

### Pattern E — Sweep line

Events: `(time, type)` where type = +1 start, -1 end (process ends first if same time).

```python
events = []
for s, e in intervals:
    events.append((s, 1))
    events.append((e, -1))
events.sort(key=lambda x: (x[0], x[1]))  # ends before starts if needed
cur = best = 0
for _, d in events:
    cur += d
    best = max(best, cur)
```

### Pattern F — Interval intersection of two lists

Two pointers on sorted lists.

### Pattern G — Video stitching / jump covering

Greedy extend farthest end within current reach.

### Inclusive vs exclusive

Clarify: does `[1,2]` overlap `[2,3]`?  
- Meetings usually **end == start is OK** (no overlap)  
- Closed intervals may differ  

---

## Associated LeetCode problems

### Easy

| # | Problem |
|---|---------|
| 228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges/) |
| 252 | Meeting Rooms (Premium) |
| 989 | Add to Array-Form (not interval) skip |

### Medium

| # | Problem |
|---|---------|
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) |
| 57 | [Insert Interval](https://leetcode.com/problems/insert-interval/) |
| 435 | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) |
| 252 | Meeting Rooms (Premium) |
| 253 | Meeting Rooms II (Premium) |
| 986 | [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) |
| 452 | [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) |
| 1288 | [Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/) |
| 763 | [Partition Labels](https://leetcode.com/problems/partition-labels/) | Interval merge flavor |
| 1024 | [Video Stitching](https://leetcode.com/problems/video-stitching/) |
| 1326 | [Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/) |
| 1094 | [Car Pooling](https://leetcode.com/problems/car-pooling/) | Diff array / sweep |
| 731 | [My Calendar II](https://leetcode.com/problems/my-calendar-ii/) |
| 729 | [My Calendar I](https://leetcode.com/problems/my-calendar-i/) |
| 1851 | [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/) | Heap |

### Hard

| # | Problem |
|---|---------|
| 352 | [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/) |
| 715 | [Range Module](https://leetcode.com/problems/range-module/) |
| 850 | [Rectangle Area II](https://leetcode.com/problems/rectangle-area-ii/) |
| 759 | Employee Free Time (Premium) |

---

## Chapter exit criteria

- [ ] Merge + Insert intervals cold
- [ ] Min meeting rooms (heap or two pointers)
- [ ] Min removals non-overlapping via sort-by-end
- [ ] Sweep line for max concurrent
