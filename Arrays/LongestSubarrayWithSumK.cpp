/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
*/

/*
approach
Since the array may contain negative and zero values, the sliding window technique cannot be applied.
We use the prefix sum technique with a map to efficiently find the longest subarray whose sum equals k.

We iterate through the array while maintaining a running prefix sum.
If at any index the prefix sum equals k, the subarray from index 0 to that index is valid.
Otherwise, we check whether (currentSum − k) has appeared before. If it has, the subarray between the previous index and the current index has sum k, and we update the maximum length.

To ensure the longest subarray, we store only the first occurrence of each prefix sum in the map.

This approach runs in O(n) time with O(n) extra space.
*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int mxLen=0;
        int n = arr.size();
        int sum=0;
        map<int , int> preSum;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                mxLen=max(mxLen,i+1);
            }
            int rem=sum-k;
            if(preSum.find(rem)!=preSum.end()){
                mxLen=max(mxLen,i-preSum[rem]);
            }
            if(preSum.find(sum)==preSum.end()){preSum[sum]=i;} // for tc that contains 0 
            //2 0 0 0 3 and k=3 
        }
        return mxLen;
    }
};