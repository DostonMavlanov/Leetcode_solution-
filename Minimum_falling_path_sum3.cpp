#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int matrixSize = matrix.size(); 
        vector<int> prevRowCosts(matrixSize); 

        for (auto& row : matrix) {
            vector<int> currentRowCosts = prevRowCosts; 

            for (int j = 0; j < matrixSize; ++j) {
                if (j > 0) {
                    currentRowCosts[j] = min(currentRowCosts[j], prevRowCosts[j - 1]); 
                }
                if (j + 1 < matrixSize) {
                    currentRowCosts[j] = min(currentRowCosts[j], prevRowCosts[j + 1]); 
                }
                currentRowCosts[j] += row[j]; 
            }
            prevRowCosts = move(currentRowCosts);
        }
        return *min_element(prevRowCosts.begin(), prevRowCosts.end());
    }
};