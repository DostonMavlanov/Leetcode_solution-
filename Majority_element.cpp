#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num: nums){
            if (count == 0){
                candidate = num;
                count = 1;
            }else{
                count += (candidate == num) ? 1 : -1;
            }
        }
        return candidate;
    }
};