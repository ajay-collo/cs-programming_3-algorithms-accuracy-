#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getMinimumCoins(int amount, std::vector<int> denominations) {
    // Sort denominations in descending order (largest first) to enable the greedy choice
    std::sort(denominations.begin(), denominations.end(), std::greater<int>());
    
    std::vector<int> changeGiven;
    
    for (int coin : denominations) {
        // Greedily use the largest coin as many times as it fits
        while (amount >= coin) {
            amount -= coin;
            changeGiven.push_back(coin);
        }
    }
    
    // If the amount isn't 0, the given coins can't make exact change
    if (amount > 0) {
        return {}; // Return empty vector indicating failure
    }
    
    return changeGiven;
}

int main() {
    // Standard US coin denominations: Quarter (25), Dime (10), Nickel (5), Penny (1)
    std::vector<int> standardCoins = {25, 10, 5, 1};
    int targetAmount = 87;
    
    std::vector<int> result = getMinimumCoins(targetAmount, standardCoins);
    
    std::cout << "Target Amount: " << targetAmount << " cents\n";
    
    if (result.empty()) {
        std::cout << "Cannot make exact change with these denominations.\n";
    } else {
        std::cout << "Coins used: ";
        for (int coin : result) {
            std::cout << coin << " ";
        }
        std::cout << "\nTotal coins needed: " << result.size() << "\n";
    }
    
    return 0;
}
