/*
Problem statement
Given a sequence of numbers. Find all leaders in sequence. An element is a leader if it is strictly greater than all the elements on its right side.

Note:
1. Rightmost element is always a leader.

2. The order of elements in the return sequence must be the same as the given sequence
Example:
The given sequence is 13, 14, 3, 8, 2 .

13 Not a leader because on the right side 14 is greater than 13.

14 lt is a leader because no one greater element in the right side.

3 Not a leader because on the right side 8 are greater than 3.

8 It is a leader because no one greater element on the right side.

2 It is a leader because it is the rightmost element in a sequence.

Hence there are 3 leaders in the above sequence which are 14, 8, 2.
*/

/*
approach:
    brute:
        run 2 loops 
            one for iteration and one for finding whether the element has any greater element on the right side or not 
            if not then add it in the ans array
    optimal:
        traverse from back and keep track of the maximum element seen so far
            if the current element is greater than max till now then add it to the ans array and update the max
        at last reverse the ans array to maintain the order

*/

#include <bits/stdc++.h> 

vector<int> findLeaders(vector<int> &arr, int n) {
    // Write your code here.
    vector<int>ans;
    int maxi=arr[n-1];
    ans.push_back(maxi);
    for(int i=n-2 ; i>=0 ; i--){
        if(arr[i]>maxi){
            maxi=arr[i];
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}