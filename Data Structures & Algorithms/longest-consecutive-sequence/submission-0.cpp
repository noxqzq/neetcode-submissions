class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(), nums.end());
        int longest = 0;

        for (int num : seq) {
            if (seq.find(num - 1) == seq.end()) {
                int currentNum = num;
                int length = 1;

                while (seq.find(currentNum + 1) != seq.end()) {
                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
