class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, r=*max_element(nums.begin(),nums.end());
        auto can=[&](int d){
            long long sum=0;
            for(int x:nums) sum+=(x+d-1)/d;
            return sum<=threshold;
        };
        while(l<r){
            int mid=l+(r-l)/2;
            if(can(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
