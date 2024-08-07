#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total = 0;
        for (int value: nums){
            total += value;
            pq.push(value);
        }

        double targetHalf = total / 2.0;
        int result = 0;

        while (total > targetHalf){
            double max_num = pq.top() / 2.0;
            pq.pop();
            total -= max_num;
            pq.push(max_num);
            result++;
        }
        return result;
    }
};