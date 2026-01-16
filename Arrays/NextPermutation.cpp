/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
*/

/*
approach:
    brute:
        generate all the permutations of the array and store them in a container
        sort the container
        find the given array in the container and return the next permutation
        but that will take  O(n!*n) Time complexity
    better:
        use the stl function next_permutation(nums.begin(), nums.end())
    optimal:
        ind=-1
        find the longest prefix match 
            -for that we will traverse from back and find an index such that nums[i]<nums[i+1] and keep the index saved in variable ind 
            -after traversal if ind is still -1 that means the array is in descending order so we will reverse the array and return
            then we will again traverse from back and find an index such that nums[j]>nums[ind]
            -swap nums[ind] and nums[j]
            -reverse or sort the array from ind+1 to end


        

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // nums= 2,1,5,4,3,0,0
        // the break point is where the value is 1 coz from last 1<5 
        int n = nums.size();
        if (n <= 1) return;

        int ind = -1;

        // Step 1: find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i; //ind=1
                break;
            }
        }

        // Step 2: if no pivot, reverse entire array
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: swap with next greater element
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]); //nums=2,3,5,4,1,0,0
                break;
            }
        }

        // Step 4: reverse suffix
        reverse(nums.begin() + ind + 1, nums.end()); //nums= 2,3,0,0,1,4,5
    }
};
