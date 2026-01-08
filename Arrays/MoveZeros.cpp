/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

/*
approach 
for this we will use two pointer approach we will keep a fixed pointer(i) and then iterate using another pointer(j)
if nums[j]!=0 then we will assign the value nums[i] to nums[j] and increment i
and then for the rest of the array we will mark them 0
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
            }
        }
        for(;i<n;i++) nums[i]=0;
    }
};