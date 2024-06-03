#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, int newColor, int iniColor) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != iniColor)
            return;
        
        image[row][col] = newColor;
        
        dfs(row + 1, col, image, newColor, iniColor);
        dfs(row - 1, col, image, newColor, iniColor);
        dfs(row, col + 1, image, newColor, iniColor);
        dfs(row, col - 1, image, newColor, iniColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        if (iniColor == newColor) return image;
        dfs(sr, sc, image, newColor, iniColor);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);

    for (const auto& row : ans) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
