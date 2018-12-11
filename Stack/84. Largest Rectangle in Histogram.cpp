

/*
  利用栈求解

*/




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
       stack<int>st;
        int Max=0;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty() || heights[i]>=st.top())
            {
                st.push(heights[i]);
            }
            else{
                int count=0;
                while(!st.empty()&&st.top()>heights[i])
                {
                    count++;
                    Max=max(Max,count*st.top());
                    st.pop();
                }
                while(count--)
                {
                    st.push(heights[i]);
                }
                st.push(heights[i]);
            }
        }
        int count=0;
        while(!st.empty())
        {
            count++;
            Max=max(Max,st.top()*count);
            st.pop();
        }
        return Max;
        
    }
};
