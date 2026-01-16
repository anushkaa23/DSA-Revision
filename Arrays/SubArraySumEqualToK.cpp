/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/
    
/*
approach:
    we will use a map to store the frequency of the sum that occured and also initialize the sum with 0 and frequency of sum 0 as 1
    then we will iterate through the array and keep adding the elements to sum
    then we will check if sum-k is present in the map or not if present we will add its frequency to ans
    finally we will increase the frequency of sum in map by 1
    we are doing this because if we have sum-k in the map it means there is a subarray with sum k
    we will return ans at the end

*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(auto i : nums){
            sum+=i;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};