class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto &p : mp) {
            pq.push({p.second, p.first});
        }

        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
