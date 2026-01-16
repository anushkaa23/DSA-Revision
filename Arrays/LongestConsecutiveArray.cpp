/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

/*
approach:
    Approach (Sorting Based):

1. If the array is empty, return 0 immediately since no sequence exists.

2. Sort the array in ascending order.
   - Sorting places consecutive numbers next to each other.
   - Duplicate values will also become adjacent, making them easy to ignore.

3. Initialize:
   - lastSmallest to track the previous element in the current sequence.
   - cnt to count the length of the current consecutive sequence.
   - longest to store the maximum sequence length found so far.

4. Traverse the sorted array:
   - If the current element is exactly 1 greater than lastSmallest,
     it continues the consecutive sequence.
   - If the current element is equal to lastSmallest, it is a duplicate
     and should be skipped.
   - Otherwise, the sequence is broken and a new sequence starts.

5. Update the longest length after each valid extension.

6. Return the value of longest as the final answer.

Time Complexity:
- O(n log n) due to sorting.

Space Complexity:
- O(1) extra space (excluding the space used by sorting).
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int lastSmallest=INT_MIN;
        int cnt=0;
        int longest=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastSmallest){
                cnt++;
                lastSmallest=nums[i];
            }
            else if(nums[i]==lastSmallest){
                continue;
            }
            else{
                cnt=1;
                lastSmallest=nums[i];
            }
            longest=max(cnt,longest);
        }
        return longest;
    }
};