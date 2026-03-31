class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;        
        int prev1 = nums[0];  

        for(int i = 2; i <= n; i++) {
            int curr = max(prev2 + nums[i-1], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};