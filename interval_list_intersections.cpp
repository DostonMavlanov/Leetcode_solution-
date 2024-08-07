#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int len1 = firstList.size();
        int len2 = secondList.size();
        int i = 0;
        int j = 0;

        while (i < len1 && j < len2){
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);

            if (l <= r){
                result.push_back({l, r});
            }

            if (firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return result;
    }
};