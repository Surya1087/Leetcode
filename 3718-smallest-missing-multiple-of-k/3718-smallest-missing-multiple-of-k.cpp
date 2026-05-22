class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                s.insert(nums[i]);
            }
        }
        int expected = k;
        for(auto it :s) {
            if(it !=expected) {
                return expected;
            }
            expected+= k;
        }
        return (s.size()+1)*k;
    }
};