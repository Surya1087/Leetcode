class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n<1||n>300) return;
        else{
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(nums[i]>nums[j]){
                        swap(nums[i],nums[j]);
                    }
                }

            }
            for(int i=0;i<n;i++){
                cout<<nums[i]<<",";
            }
        }
        
    }
};