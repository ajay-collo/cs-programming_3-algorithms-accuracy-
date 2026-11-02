#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLargestInCircularArray(const vector<int>& A, int k) {
        int n = A.size();
        if (n == 0) return -1;
        
        int targetIndex = (k == 0) ? (n - 1) : (k - 1);
        
        return A[targetIndex];
    }
};

int main() {
    Solution sol;
    
    vector<int> A1 = {35, 42, 5, 15, 27, 29};
    int k1 = 2;
    cout << "Largest number in A1: " << sol.findLargestInCircularArray(A1, k1) << endl;

    vector<int> A2 = {27, 29, 35, 42, 5, 15};
    int k2 = 4;
    cout << "Largest number in A2: " << sol.findLargestInCircularArray(A2, k2) << endl;

    return 0;
}
