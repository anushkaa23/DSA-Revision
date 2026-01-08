/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/

/*
approach
the sum of n number from 0 to n is n*(n+1)/2
take the sum of n numbers and total sum of the array 
return n*(n+1)/2 - sum of array
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int nSum=n*(n+1)/2;
        return nSum-sum;
    }
};