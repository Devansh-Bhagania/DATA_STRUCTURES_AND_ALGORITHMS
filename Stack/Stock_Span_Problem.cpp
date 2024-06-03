#include <iostream>
#include <vector>

// Function to calculate stock span
std::vector<int> calculateSpan(const std::vector<int>& prices) {
    std::vector<int> span(prices.size());
    
    // Iterate through each price
    for (size_t i = 0; i < prices.size(); ++i) {
        int count = 1; // At least the current day itself
        
        // Check previous prices
        for (int j = i - 1; j >= 0 && prices[j] <= prices[i]; --j) {
            ++count;
        }
        
        span[i] = count;
    }
    
    return span;
}

int main() {
    std::vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> span = calculateSpan(prices);
    
    std::cout << "Stock span: ";
    for (int s : span) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
