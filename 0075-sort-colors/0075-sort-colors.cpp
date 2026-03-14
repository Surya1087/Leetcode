#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //int count0 = 0, count1 = 0, count2 = 0;
        //for (int num : nums) {
        //    if (num == 0) count0++;
        //   else if (num == 1) count1++;
        //   else count2++;}
        //int i = 0;
        //while (count0--) nums[i++] = 0;
        //while (count1--) nums[i++] = 1;
        //while (count2--) nums[i++] = 2;
        int n = nums.size();
        int mid,low = 0,high =n-1;
        while(mid<=high){
            if (nums[mid]==0){
                swap(nums[low],nums[mid]);{
                    mid++,low++;
                }
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);{
                    high--;
                }
            }
        }
    }
};

        
       