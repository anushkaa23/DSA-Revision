/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mx=INT_MIN;
        int secMax=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>mx){
                secMax=mx;
                mx=arr[i];
                
            }
            else if(arr[i]>secMax and arr[i]<mx){
                secMax=arr[i];
            }
        }
        return secMax;
        
    }
};