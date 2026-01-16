/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i =0;
        int sum=0;
        int n = nums.size();
        int j = n-1;
        vector<pair<int,int>> numInd;
        for(int i=0;i<n;i++){
            numInd.push_back({nums[i],i});
        }
        sort(numInd.begin(),numInd.end());
        
        while(i<j){
            sum=numInd[i].first+numInd[j].first;
            if(sum==target){
                return {numInd[i].second, numInd[j].second};
            }
            if(sum> target ) j--;
            if(sum<target) i++;
        }
        return {-1,-1};
    }
};