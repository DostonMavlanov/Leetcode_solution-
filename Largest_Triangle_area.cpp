#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;

        for (auto& point1: points){
            int x1 = point1[0], y1 = point1[1];
            for (auto& point2: points){
                int x2 = point2[0], y2 = point2[1];
                for (auto& point3: points){
                    int x3 = point3[0], y3 = point3[1];

                    int vector1X = x2 - x1, vector1Y = y2 - y1;
                    int vector2X = x3 - x1, vector2Y = y3 - y1;

                    double area = abs(vector1X * vector2Y - vector2X * vector1Y) / 2.0;
                    result = max(area, result); 
                }
            }
        }
        return result;  
    }
};