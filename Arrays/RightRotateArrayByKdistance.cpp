/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        // 1,2,3,4,5,6,7  k =3
        reverse(nums.begin(),nums.end());
        // 7,6,5,4,3,2,1
        reverse(nums.begin(),nums.begin()+k);
        // 5,6,7,4,3,2,1
        reverse(nums.begin()+k,nums.end());
        // 5,6,7,1,2,3,4
    }
};
/*
to do the left rotation 
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
Expected output= [4, 5, 6, 7, 1, 2, 3]
so first reverse the array from begin to k  -> 3,2,1,4,5,6,7
then from k to last -> 3,2,1,7,6,5,4
then reverse the whole array -> 4,5,6,7,1,2,3
*/