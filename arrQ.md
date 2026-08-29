# Meeting Rooms II (Minimum Rooms Required)

## Problem Description
Given an array of meeting time intervals `intervals` where `intervals[i] = [start_i, end_i]`, return the **minimum number of conference rooms** required to schedule all meetings without overlaps.

### Examples
* **Example 1:**
  * **Input:** `intervals = [[0, 30], [5, 10], [15, 20]]`
  * **Output:** `2`
* **Example 2:**
  * **Input:** `intervals = [[7, 10], [2, 4]]`
  * **Output:** `1`

---

## Optimal Strategy
* **Sorting + Min-Heap:** 
  1. Sort intervals by start time in ascending order.
  2. Maintain a Min-Heap of meeting **end times**.
  3. If the top of the heap (earliest finishing meeting) finishes before or at the current meeting's start time, pop it (reuse the room).
  4. Push the current meeting's end time.

## Complexity Analysis
* **Time Complexity:** $O(N \log N)$ due to sorting and heap operations.
* **Space Complexity:** $O(N)$ for auxiliary min-heap space.