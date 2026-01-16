/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/


/*
approach:
apply kadanes algo 
initialise 2 variables 
sum=0 and ans=INT_MAX
iterate over the array and add the element to the sum
and check
    if(sum>ans) ans=sum
    if(sum<0)sum=0
atlast return ans
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int ans=INT_MIN;
       int sum=0;
       int n = nums.size();
       for(int i=0;i<n;i++){
            if(sum<0){
                sum=0;
            }
            sum+=nums[i];
            if(sum>ans) ans=sum;
       } 
       return ans;
    }
};