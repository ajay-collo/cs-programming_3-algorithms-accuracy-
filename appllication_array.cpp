#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    //   start time
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    // 2. Min-Heap 
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 3. Process each meeting
    for (const auto& meeting : intervals) {
        int start = meeting[0];
        int end = meeting[1];

        // If a room becomes free before
        if (!minHeap.empty() && minHeap.top() <= start) {
            minHeap.pop();
        }

        // Push current meeting's end time
        minHeap.push(end);
    }

    // 4. Size of heap equals minimum rooms required
    return minHeap.size();
}

int main() {
    std::vector<std::vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    std::cout << "Example 1 Rooms Required: " << minMeetingRooms(intervals1) << std::endl;

    std::vector<std::vector<int>> intervals2 = {{7, 10}, {2, 4}};
    std::cout << "Example 2 Rooms Required: " << minMeetingRooms(intervals2) << std::endl;

    return 0;
}
