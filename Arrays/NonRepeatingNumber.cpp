/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [4,1,2,1,2]

Output: 4
*/


/*
approach
use the xor property -> the xor of two same number is 0 
so all the repeating numbers will get cancelled and the non repeating will be left
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};