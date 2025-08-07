class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n<1||n>5*10000){
            return -1;
        }
        else{
            sort(nums.begin(),nums.end());
            return nums[n/2];
        }
        
    }
};