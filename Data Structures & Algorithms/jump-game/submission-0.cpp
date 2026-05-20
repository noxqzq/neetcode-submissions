class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int target = n - 1;
        int reachable = 0;

        while(i <= reachable) {
            reachable = max(reachable, i + nums[i]);
            if(reachable >= target) {
                return true;

            }
            i++;
            if (i >= n) break;
        }
        return false;
    }
};
