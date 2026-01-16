/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

/*
approach
This approach is a direct implementation of the Dutch National Flag algorithm.
We divide the array into three partitions using three pointers – low, mid, and high.
From 0 to low-1, we’ll keep only 0s
From low to mid-1, only 1s
From mid to n-1, only 2
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0 , mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};