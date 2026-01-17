/*
Given an array arr[] and k, where the array represents the boards and each element of the given array represents the length of each board. k numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. The task is to find the minimum time to get this job done by painting all the boards under the constraint that any painter will only paint the continuous sections of boards. say board [2, 3, 4] or only board [1] or nothing but not board [2, 4, 5].

Examples: 

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20, 15], Job will be done when all painters finish i.e. at time = max(5 + 10, 30, 20 + 15) = 35
*/

/*
Approach:

Each board takes time equal to its length to paint, and each painter can
only paint a continuous section of boards. We want to minimize the total
time required, which is determined by the painter who finishes last
(i.e., the maximum time taken by any painter).

The minimum possible time must be at least the maximum length of a single board, because a board cannot be split between painters.

The maximum possible time can be the sum of all board lengths, which happens when only one painter paints all the boards.

So, the answer lies in the range:
[max(arr), sum(arr)]

We apply Binary Search on this range.

For a given time limit (mid), we check whether it is possible to paint all boards using at most k painters such that no painter paints more than mid units of time.

To check feasibility:
- Start assigning boards to the first painter and keep adding board lengths while the total time does not exceed mid.
- If adding a board exceeds mid, assign the board to the next painter.
- Count how many painters are required.
- If the number of painters required is less than or equal to k, then
    this time limit is feasible.

Binary Search logic:
- If it is possible to paint all boards within mid time, try to minimize the answer by searching the left half.
- If it is not possible, increase the time limit by searching the right half.

Finally, return the minimum possible time required to paint all boards.

Time Complexity:
- O(n log S), where n is the number of boards and S is the sum of all board lengths.

Space Complexity:
- O(1), since only constant extra space is used.
*/

#include<bits/stdc++.h>
using namespace std;
Class Solution{
    public:
    int solve(vector<int>& arr, int k , int limit){
        int sum=0;
        int painters=1;
        for(int i=0;i<n;i++){
            if(arr[i]>limit) return INT_MAX;
            if(sum+arr[i]<=k){
                sum+=arr[i];
            }else{
                sum=arr[i];
                painters++;
            }
        }
        return painters;
    }

    int minTime(vector<int>& arr, int k){
        int low=max_element*(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(arr,k,mid)<=k){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};