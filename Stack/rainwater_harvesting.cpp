#include <iostream>
#include <vector>

using namespace std;

int trapWater(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= leftMax ? leftMax = height[left] : water += leftMax - height[left];
            left++;
        } else {
            height[right] >= rightMax ? rightMax = height[right] : water += rightMax - height[right];
            right--;
        }
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Amount of water trapped: " << trapWater(height) << endl;
    return 0;
}
