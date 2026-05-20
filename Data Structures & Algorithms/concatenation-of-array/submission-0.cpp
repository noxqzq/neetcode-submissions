class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int amount = 2;

        while(amount != 0) {
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(nums[i]);
            }
            amount--;
        }

        return ans;
    }
};