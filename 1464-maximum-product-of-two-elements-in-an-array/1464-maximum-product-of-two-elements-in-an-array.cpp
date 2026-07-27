class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int current_Max = nums[0];

        for (int i = 1; i < n; i++) {
            ans = max(ans, (current_Max - 1) * (nums[i] - 1));
            current_Max = max(current_Max, nums[i]);
        }

        return ans;
    }
};