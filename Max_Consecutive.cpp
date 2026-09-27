#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // Your input array
    
    int count = 0;
    int maxOnes = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
        } else {
            maxOnes = max(maxOnes, count);
            count = 0; // Reset count on 0
        }
    }

    // Check last streak
    maxOnes = max(maxOnes, count);

    cout << maxOnes << "\n"; // Output: 3

    return 0;
}
