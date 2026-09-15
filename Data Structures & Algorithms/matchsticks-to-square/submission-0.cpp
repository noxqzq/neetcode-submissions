class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;

        int side = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > side) 
            return false;

        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, side);
    }

    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > target)
                continue;

            sides[i] += matchsticks[index];
            
            if (backtrack(matchsticks, sides, index + 1, target)) {
                return true;
            }
            sides[i] -= matchsticks[index];
            if (sides[i] == 0) 
                break;
        }

        return false;
    }
};