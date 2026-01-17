/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.
Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/


/*approach
    brute:
        traverse all the element and check
            if(element<=k) k++;
            else break;
        return k;
    optimal:
        we will use binary search to find the kth missing element
        we will calculate the number of missing elements till mid index using the formula arr[mid]-(mid+1)
        if the number of missing elements is less than k it means the kth missing element is on the right side so we will move low to mid+1
        else we will move high to mid-1
        finally we will return k+high+1 as the kth missing element
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0 , high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing = arr[mid]-(mid+1);
            if(k>missing){
                low=mid+1;
            }
            else high=mid-1;
        }
        // return arr[high]+k-(arr[high]-(high+1));
        return k+high+1;
    }
};
