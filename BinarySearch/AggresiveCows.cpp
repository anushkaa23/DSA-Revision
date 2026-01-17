/*
You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways
*/

/*
Approach:

We are given positions of stalls and we need to place k cows such that
the minimum distance between any two cows is as large as possible.

First, we sort the stalls array because cows must be placed in increasing
order of stall positions to maximize distance greedily.

The minimum possible distance between two cows can be 1.
The maximum possible distance can be the difference between the last
and first stall after sorting.

So, the answer lies in the range:
[1, stalls[n-1] - stalls[0]]

We apply Binary Search on this range.

For a given distance (mid), we check if it is possible to place k cows
such that the minimum distance between any two cows is at least mid.

To check this, we use a greedy approach:
- Place the first cow in the first stall.
- For each next stall, place a cow only if the distance from the last
  placed cow is greater than or equal to mid.
- Count how many cows are placed.
- If we can place at least k cows, the distance is feasible.

Binary Search logic:
- If we can place k cows with distance = mid, then this distance is valid,
  so we try to maximize it by moving to the right side.
- If we cannot place k cows, the distance is too large, so we reduce it
  by moving to the left side.

Finally, we return the maximum distance for which placing k cows is possible.

Time Complexity:
- O(n log D), where n is number of stalls and D is the search range
  (stalls[n-1] - stalls[0]).

Space Complexity:
- O(1), excluding input storage.
*/
class Solution {
  public:
    bool canWePlace(vector<int>& stalls , int dis , int k){
        int cows=1;
        int n=stalls.size();
        int last=stalls[0];
        for(int i=1;i<n;i++){
            if(dis<=stalls[i]-last){
                last=stalls[i];
                cows++;
            }
            else continue;
            if(cows>=k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int start=1,end=stalls[n-1]-stalls[0];
        while(start<=end){
            int mid=(start+end)/2;
            if(canWePlace(stalls,mid,k)){
                start=mid+1;
            }
            else end=mid-1;
        }
        return end;
    }
};