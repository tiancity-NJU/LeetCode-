
/*
  可以简单利用每一个位置的左右最大高度来度量自身高度
  但是用栈是最高效的

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
