/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/

/*
Approach:

The minimum weight capacity of the ship must be at least the maximum
element in the weights array, because a single package cannot be split.

The maximum possible capacity is the sum of all elements in the array,
since in the worst case all packages can be shipped in one day.

So, the answer lies in the range:
[max(weights), sum(weights)]

We apply Binary Search on this range to find the minimum capacity.

For a given capacity (mid), we simulate the shipping process using a
helper function:
- We load packages in order.
- If adding the next package exceeds the current capacity, we move to
  the next day and reset the load.
- We count how many days are required to ship all packages with this
  capacity.

Binary Search logic:
- If the number of days required is less than or equal to the given days,
  the capacity might be valid, so we try to minimize it by searching the
  left half.
- If the number of days required is more than the given days, the
  capacity is too small, so we search the right half.

Finally, the smallest valid capacity is returned.

Time Complexity:
- O(n log S), where n is the number of packages and S is the sum of all weights.

Space Complexity:
- O(1), since only constant extra space is used.
*/


class Solution {
public:
    int findDays(vector<int>& weights,int capacity){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=capacity){
                load+=weights[i];
            }
            else{
                load=weights[i];
                day++;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(),weights.end());
        int end=accumulate(weights.begin(),weights.end(),0);
        while(start<=end){
            int mid=(start+end)/2;
            int numberOfDays=findDays(weights,mid);
            if(numberOfDays<=days){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};