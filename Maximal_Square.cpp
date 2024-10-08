#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n ==  0) {
            return 0;
        }
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                if (i == 0 || j == 0){
                    if (matrix[i][j] == '1'){
                        dp[i][j] = 1;
                    }
                } else {
                    if (matrix[i][j] == '1'){
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i-1][j - 1]}) + 1;
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};