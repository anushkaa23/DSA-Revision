/*
You are given an array 'a' of size 'n' and an integer 'k'.



Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]

Here, the length of the longest subarray is 3, which is our final answer.
*/

/*
approach 
use the two pointer approach 
take two pointers left and right
take a variable sum and initialise it with 0
right pointer expands by including new element and increasing the sum
If the sum of the window exceeds k, the left pointer shrinks the window by removing elements from the start until the sum is less than or equal to k.
If the sum of the current window equals k, the maximum length of such a subarray is updated.
The process continues until the right pointer traverses the entire array.
Finally, the maximum length of the subarray with sum k is returned as the result.
*/

#include<map>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int mx=0;
    long long sum=0;
    int j =0 , i=0;
    while(i<n){
        if(sum<=k){
            sum+=a[i];
        }
        if(sum > k){
            sum-=a[j];
            j++;
        }
        if(sum==k and i<n){
            mx=max(mx,i-j+1);
            i++;
        }
        if (sum < k && i < a.size() ) {
            i++;
        }
    }
    return mx;
}