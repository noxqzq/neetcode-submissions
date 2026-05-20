class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int length = nums.size();
        for(int i = 0; i < length; i++) {
            for(int j = i + 1; j < length; j++) {
                if(nums.at(i) == nums.at(j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
