class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<2||n>10000){
            return {};
        }
        else{
            unordered_map<int, int> numToIndex;
            for(int i=0;i<n;i++){
                int complement=target-nums[i];
                if(numToIndex.find(complement)!=numToIndex.end()){
                    return {numToIndex[complement],i};
                }
                numToIndex[nums[i]]=i;
                    
                }

            }
            return{};
        }
        
        
    };
    
