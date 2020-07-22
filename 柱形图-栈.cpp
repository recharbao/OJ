class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0) return 0;
        stack<int> st;
        st.push(-1);
        int MAX = 0;
        int index;
        int pre_INDEX_HEIGHT;
        for(int i = 0;i < heights.size();i++)
        {
            index = st.top();
            while(index != -1 && heights[i] <heights[index])
            {
                pre_INDEX_HEIGHT = heights[index];
                st.pop();
                index = st.top();
                MAX = max((i - 1 - index) * pre_INDEX_HEIGHT,MAX);
            }
            st.push(i);
        }
        
        index = st.top();
        while(index !=-1 && !st.empty())
        {
            pre_INDEX_HEIGHT = heights[index];
            st.pop();
            index = st.top();
            MAX = max((n - 1 - index) * pre_INDEX_HEIGHT,MAX);
        }
        return MAX;
    }
   
};