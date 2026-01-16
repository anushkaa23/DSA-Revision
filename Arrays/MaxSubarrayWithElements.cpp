/*
Given an array of integers arr[], find the contiguous subarray with the maximum sum that contains only non-negative numbers. If multiple subarrays have the same sum, return the one with the smallest starting index. If the array contains only negative numbers, return -1.

Note: A subarray is a contiguous non-empty sequence of elements within an array.

Examples:

Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation: In the given array, every element is non-negative, so the entire array [1, 2, 3] is the valid subarray with the maximum sum.

*/

/*
use kananes algo and then use three pointers curr , start , end to keep the start and end of the resulting max sum array 
when arr[i]>=0
    add arr[i] to sum
    if sum>maxSum update maxSum , start and end
    else if sum==maxSum and curr==start update end to i (to get the longest subarray in case of tie)
else
    update curr to i+1 and sum to 0
atlast if maxSum==-1 return {-1} else return the subarray from start to end
*/

// User function template for C++
class Solution {
    public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int curr=0, start=-1,end=-1;
        int n = arr.size();
        int sum=0, maxSum=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                sum+=arr[i];
                if(sum>maxSum ){
                    maxSum=sum;
                    start=curr;
                    end=i;
                }
                else if (sum == maxSum && curr == start) {
                    end = i;
                }
            }else{
                curr=i+1;
                sum=0;
            }
        }
        if(maxSum==-1) return {-1};
        return vector<int>(arr.begin() + start,arr.begin() + end + 1);
    }
};