#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int len = capacity.size();
        int result = 0;

        for (int i = 0; i < len; ++i){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for (int num: capacity){
            if (num > additionalRocks){
                break;
            }
            result++;
            additionalRocks -= num;
        }
        return result;
    }
};