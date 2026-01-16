/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

/*
approach
1) Brute Force Approach (O(n^2))

Idea:
- Try all possible pairs of buy day and sell day.
- For each day i, consider it as the buying day.
- For every future day j > i, calculate profit = prices[j] - prices[i].
- Track the maximum profit among all valid pairs.
- If no profit is possible, return 0.
Steps:
1. Initialize maxProfit = 0.
2. Loop i from 0 to n-1:
   - Loop j from i+1 to n-1:
     - Calculate profit = prices[j] - prices[i].
     - Update maxProfit if profit is larger.
3. Return maxProfit.

Time Complexity: O(n^2)
Space Complexity: O(1)

------------------------------------------------------------

2) Optimized Approach (Single Pass / Kadane-like) – O(n)

Idea:
- Keep track of the minimum price seen so far (best day to buy).
- At each day, assume we sell on that day and compute profit.
- Update maximum profit if the current profit is better.
- This ensures buy always happens before sell.

Steps:
1. Initialize:
    - mini = INT_MAX (minimum buying price so far)
    - ans = 0 (maximum profit)
2. Traverse prices array:
    - Update mini = min(mini, prices[i])
    - Compute current profit = prices[i] - mini
    - Update ans = max(ans, current profit)
3. Return ans.

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), ans=INT_MIN, mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            ans=max(ans,prices[i]-mini);
        }
        return ans;
    }
};