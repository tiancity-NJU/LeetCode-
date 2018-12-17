
/*

  非常好的一题，可以通过多种方法解决
  基本解法，对每一个位置进行计算
*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int count=0;
        int i,j,k;
        for(i=0;i<height.size();i++)
        {
            int leftHeight=0,rightHeight=0;
            for(j=0;j<i;j++)
                leftHeight=max(leftHeight,height[j]);
    
            for(k=i+1;k<height.size();k++)
                rightHeight=max(rightHeight,height[k]);
            
            int tmp=min(leftHeight,rightHeight)-height[i];
            count+=tmp>0?tmp:0;
        }
        
        return count;
    }
};


/*
  上面一种解法使用O(n2)的时间代价，下面方法利用空间换时间，将时间压缩到O(n)，但是同样的空间代价从O(1) -> O(n) 利用left right数组记录
  左右的最大高度，时间也从364ms -> 12ms
*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int count=0;
        int i,j,k;
        vector<int>left(height.size(),0),right(height.size(),0);
        int tmp=0;
        for(i=0;i<height.size();i++)
        {
            left[i]=tmp;
            tmp=max(tmp,height[i]);
        }
        tmp=0;
        for(i=height.size()-1;i>=0;i--)
        {
            right[i]=tmp;
            tmp=max(tmp,height[i]);
        }
        
        for(i=0;i<height.size();i++)
        {
            tmp=min(left[i],right[i])-height[i];
            count+=tmp>0?tmp:0;
        }
        return count; 
    }
};

/*
  还有一一种在网上看到的双指针方法，这样能够将在不增长时间复杂度的前提下降低空间复杂度
*/

   class Solution {
public:
    int trap(vector<int>& height) {
        
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
  }
};


/*
  最后当然还是利用栈的方法，这个问题和砖块最大面积的问题很像，stack是一个难点
*/

class Solution {
public:
    int trap(vector<int>& height)
    {
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
    }
};
