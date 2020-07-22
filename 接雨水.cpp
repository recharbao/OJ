class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> height_index;
        height_index.push(-1);
        int count = 0;
        int sum = 0;
        int n = height.size();
        for(int i = 0; i < n; i++)
        {
            if(height_index.empty())
            {
                height_index.push(i);
            }
            else
            {
                int index;
                bool ok = true;
                while(height_index.top() != -1 && height[height_index.top()] <= height[i])
                {
                    ok = false;
                    index = height_index.top();
                    //cout<<index<<endl;
                    count += height[height_index.top()];
                    height_index.pop();
                }
                if(ok)
                {
                    height_index.push(i);
                }
                else
                {
                    if(height_index.top() == -1)
                    {
                       
                        sum += (height[index] * (i - index) - count);
                        count = 0;
                    }
                    else
                    {
                        sum += (height[i] * (i - height_index.top()-1) - count);
                        count += (height[i] * (i - height_index.top()-1) - count);
                        cout<<"count = "<<count<<endl;
                        cout<<"sum1 ="<<sum<<endl;
                    }
                    height_index.push(i);
                }
            }
        }
        return sum;
    }
};
