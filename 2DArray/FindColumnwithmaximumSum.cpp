// C++ program to find column with
// max sum in a matrix
#include<iostream>
using namespace std;
 
#define N 5 // No of rows and column
 
// Function to find the column with max sum
pair<int, int> colMaxSum(int mat[N][N])
{
    // Variable to store index of column
    // with maximum
    int idx = -1;
 
    // Variable to store max sum
    int maxSum = INT_MIN;
 
    // Traverse matrix column wise
    for (int i = 0; i < N; i++) {
        int sum = 0;
 
        // calculate sum of column
        for (int j = 0; j < N; j++) {
            sum += mat[j][i];
        }
 
        // Update maxSum if it is less than
        // current sum
        if (sum > maxSum) {
            maxSum = sum;
 
            // store index
            idx = i;
        }
    }
 
    pair<int, int> res;
 
    res = make_pair(idx, maxSum);
 
    // return result
    return res;
}
 
// driver code
int main()
{
 
    int mat[N][N] = {
        { 1, 2, 3, 4, 5 },
        { 5, 3, 1, 4, 2 },
        { 5, 6, 7, 8, 9 },
        { 0, 6, 3, 4, 12 },
        { 9, 7, 12, 4, 3 },
    };
 
    pair<int, int> ans = colMaxSum(mat);
 
    cout << "Column " << ans.first + 1 << " has max sum "
         << ans.second;
 
    return 0;
}