#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<int> dp(n, 0); // Initialize dp vector

        // Bottom-up calculation
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // Move to either index j or j+1 on the next row
                if (i == n - 1) { // Base case: last row
                    dp[j] = triangle[i][j];
                } else {
                    dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j]; // Choose the minimum path
                }
            }
        }
    return dp[0];
    }
};