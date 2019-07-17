// 来自https://leetcode.com/problems/max-points-on-a-line/discuss/47106/C%2B%2B-O(n2)-solution-for-your-reference，用最大公约数来防止求斜率带来的float型运算
class Solution {
public:
    int GCD(int a, int b) {
        if(b == 0) return a;
        else return GCD(b, a % b);
    }
    
    int maxPoints(vector<vector<int>> &points) {
        if(points.size() < 2) 
            return points.size();     
        int result = 0;
        for(int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> lines;
            int localmax = 0;
            int overlap = 0;   // 重复点
            int vertical = 0;  // 垂直点
            for(int j = i + 1; j < points.size(); j++) {
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) {      
                    overlap++;
                    continue;
                }
                else if(points[j][0] == points[i][0]) 
                    vertical++;
                else {
                    int a = points[j][0] - points[i][0], b = points[j][1] - points[i][1];
                    int gcd = GCD(a, b);
                    a /= gcd;
                    b /= gcd;
                    lines[{a, b}]++;
                    localmax = max(lines[{a, b}], localmax);
                }
                localmax = max(vertical, localmax);
            }
            result = max(result, localmax + overlap + 1);
        }
        return result;
    }
};
