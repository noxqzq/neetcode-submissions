class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        for (int i = 0; i < matrix.size(); i++) {
        int left = 0;
        int right = matrix[i].size() - 1;
            while(left <= right) {
                int mid = (left + right)/2;
                if(matrix[i][mid] == target) {
                    return true;
                }
                else if(matrix[i][mid] < target){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

        }
        return false;        
    }

};


/*
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = (left + right)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
*/
