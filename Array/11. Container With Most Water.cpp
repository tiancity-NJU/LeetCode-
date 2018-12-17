/*
     本身是个two points 问题，我们把这些问题都放在数组Array里面
     这个问题有点类似于后面的： 给定不同长度的矩阵依次排列，寻找最大面积
     只需要左右相对逼近，每次更新小的边，与MAX比较，记录最大MAX
     这一题不用考虑中间的高度，所以不用那个栈
     author: ztc
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 1)
			return 0;

		int left = 0;
		int right = height.size() - 1;
		int maxAera = (right-left)*min(height[left],height[right]);
		while (left < right)
		{
			if (height[left] < height[right])
			{
				left += 1;
			}
			else {
				right -= 1;
			}
			maxAera = max(maxAera, (right - left)*min(height[left], height[right]));
		}
		return maxAera;
        
    }
};



/*
author: ypz
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area;
        int ans = 0;
        for(int i = 0; i < height.size() - 1; i++) {
            for(int j = i + 1; j < height.size(); j++) {
                area = min(height[i], height[j]) * (j - i);
                if(area > ans) {
                    ans = area;
                }
            }
        }
        return ans;
        
    }
};
