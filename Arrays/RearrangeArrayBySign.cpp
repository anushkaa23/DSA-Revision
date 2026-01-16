/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.



Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 
*/

/*
approach:
use to variables for indexes of negative and postive numbers
initialize negInd=1 and posInd=0
create an answer array of size n initialized with 0
traverse the nums array
if the current number is negative, place it at negInd index of answer array and increment negInd by 2
if the current number is positive, place it at posInd index of answer array and increment posInd by 2
return the answer array
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int negInd=1 , posInd=0;
        int n= nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negInd]=nums[i];
                negInd+=2;
            }
            else{
                ans[posInd]=nums[i];
                posInd+=2;
            }
        }
        return ans;
    }
};