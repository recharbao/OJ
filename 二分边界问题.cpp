class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(up < down)
        {
            int mid = down - (down - up) >> 1;
            if(target >= matrix[mid][0])
            {
                up = mid;
            }
            else if(target < matrix[mid][0])
            {
                down = mid - 1;
            }
        }

        while(left < right)
        {
            int mid = left + (right - left) >> 1;
            if(target > matrix[up][mid])
            {
                left = mid + 1;
            }
            else if(target <= matrix[up][mid])
            {
                right = mid;
            }
        }
        
         return matrix[up][left] == target;
    }
};