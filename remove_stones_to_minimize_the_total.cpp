#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int x: piles){
            pq.push(x);
        }
        while (k-- > 0){
            int max_num = pq.top();
            pq.pop();
            pq.push((max_num + 1) / 2);
        }
        int sum = 0;
        while (!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
