class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int minm = INT_MAX;
        int maxm = INT_MIN;
        for (int i = 0; i < n; i++) {
            minm = min(minm, nums[i]);
            maxm = max(maxm, nums[i]);
        }

        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        vector<int> ans;
        for (int i = minm; i <= maxm; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};