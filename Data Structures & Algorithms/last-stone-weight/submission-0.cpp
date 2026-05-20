class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> smash;

        for (int stone : stones) {
            smash.push(stone);
        }

        while (smash.size() > 1) {
            int first = smash.top();
            smash.pop();

            int second = smash.top();
            smash.pop();

            if (first != second) {
                smash.push(first - second);
            }
        }

        return smash.empty() ? 0 : smash.top();
    }
};
