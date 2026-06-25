class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end()); 
        int tmp{};
        for (int val : set1) {
            if (set2.count(val)) {
                res.push_back(val);
            }
        }
        return res;
    }
};