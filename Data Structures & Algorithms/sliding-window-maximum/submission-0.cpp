class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxs;
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int maximum = nums[i];
            for (int j = i + 1; j < i + k; j++)
                maximum = max(maximum, nums[j]);
            maxs.push_back(maximum);
        }
        return maxs;
    }
};
