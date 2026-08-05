class Solution {
public:
    int trap(vector<int>& height) {
    //     int n = height.size();
    //     int leftmax[20000];
    //     leftmax[0] = height[0];
    //     int rightmax[20000];
    //     rightmax[n-1] = height[n-1];
    //     for(int i = 1;i<n;i++){
    //         leftmax[i] = max(leftmax[i-1],height[i-1]);
    //     }
    //     for(int i = n-2;i>=0;i--){
    //         rightmax[i] = max(rightmax[i+1],height[i+1]);
    //     }
    //     int watertrapped = 0;
    //     for(int i = 0;i<n;i++){
    //         int currwater = min(leftmax[i],rightmax[i]) - height[i];
    //         if(currwater > 0){
    //             watertrapped += currwater;
    //         }
    //     }
    //     return watertrapped;

        
    // }

        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];

                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];

                right--;
            }
        }

        return water;
    }
};