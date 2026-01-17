/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

*/


/*
Approach:

The minimum possible value of the maximum sum among the subarrays must be
at least the maximum element in the array, because a single element
cannot be split across subarrays.

The maximum possible value of the maximum sum can be the sum of all
elements in the array, which happens when the entire array is taken as
one subarray.

So, the answer lies in the range:
[max_element(nums), sum_of_all_elements]

We apply Binary Search on this range.

For a given value (mid), we check how many subarrays are required if we
restrict each subarray to have a sum of at most mid.

To check this:
- We iterate through the array and keep adding elements to the current subarray.
- If adding an element exceeds the limit (mid), we start a new subarray and increase the partition count.
- This greedy process ensures contiguous subarrays.

Binary Search logic:
- If the number of subarrays required is less than or equal to k, then it is possible to split the array with this maximum sum, so we try to minimize it by searching the left half.
- If more than k subarrays are required, the limit is too small, so we increase the limit by searching the right half.

Finally, we return the minimum possible value of the maximum subarray sum.

Time Complexity:
- O(n log S), where n is the size of the array and S is the sum of all elements.

Space Complexity:
- O(1), since only constant extra space is used.
*/

class Solution {
public:
    int solve(vector<int>& nums, int k, int limit){
        int partition=1;
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i] <= limit ){
                sum+=nums[i];
            }else{
                partition++;
                sum=nums[i];
                
            }
        }
        return partition;
        
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int partitions=solve(nums,k, mid);
            if(partitions<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};