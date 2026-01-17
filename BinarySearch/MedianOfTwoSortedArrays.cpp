/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0 , j=0, n1=nums1.size() , n2=nums2.size();
        int n=n1+n2;
        int ind2=n/2 , ind1=ind2-1, cnt=0;
        int ele1=0;
        int ele2=0;
        while(i<n1 and j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1)ele1= nums1[i];
                if(cnt==ind2)ele2= nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt==ind1)ele1= nums2[j];
                if(cnt==ind2)ele2= nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(cnt==ind1)ele1= nums1[i];
                if(cnt==ind2)ele2= nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
            if(cnt==ind1)ele1= nums2[j];
                if(cnt==ind2)ele2= nums2[j];
                cnt++;
                j++;
        }
        if((n1+n2)%2) return (double)ele2;
        return (double)(double(ele1+ele2)/2.0);
    }
};