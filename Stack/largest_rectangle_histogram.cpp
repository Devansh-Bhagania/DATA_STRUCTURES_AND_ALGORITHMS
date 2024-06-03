#include <iostream>
#include <vector>
#include <algorithm> // For std::min

// Function to calculate the largest rectangle area in a histogram
int largestRectangleArea(const std::vector<int>& heights) {
    int maxArea = 0;
    int n = heights.size();
    
    // Iterate through each bar
    for (int i = 0; i < n; ++i) {
        int minHeight = heights[i];
        
        // Expand the rectangle to the right
        for (int j = i; j < n; ++j) {
            minHeight = std::min(minHeight, heights[j]);
            int width = j - i + 1;
            int area = minHeight * width;
            maxArea = std::max(maxArea, area);
        }
    }
    
    return maxArea;
}

int main() {
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = largestRectangleArea(heights);
    
    std::cout << "Largest rectangle area: " << maxArea << std::endl;
    
    return 0;
}
