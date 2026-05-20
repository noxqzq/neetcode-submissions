class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxS = 0;

        while (i < j) {
            int length = j - i;
            int height = min(heights[i], heights[j]);
            int tempS = length * height;

            maxS = max(maxS, tempS);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxS;
    }
};
