class Solution {
public:
    int noOfDays(int capacity, vector<int>& weights){
        int days=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>capacity){
                sum=weights[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
            if(weights[i]>low)
                low=weights[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(noOfDays(mid, weights)>days)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};