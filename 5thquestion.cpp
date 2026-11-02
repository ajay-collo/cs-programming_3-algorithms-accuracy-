#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string searchString, string magazine) {
        if (searchString.length() > magazine.length()) return false;
        
        vector<int> charCount(256, 0);
        
        for (char c : magazine) {
            charCount[c]++;
        }
        
        for (char c : searchString) {
            charCount[c]--;
            if (charCount[c] < 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    string magazine = "programmingalgorithms";
    string searchString = "algo";

    if (sol.canConstruct(searchString, magazine)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
