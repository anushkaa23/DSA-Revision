/*Start with the second element as the first element is assumed to be sorted.
Compare the second element with the first if the second is smaller then swap them.
Move to the third element, compare it with the first two, and put it in its correct position
Repeat until the entire array is sorted.*/
#include <bits/stdc++.h>
using namespace std;    
void insertionSort(vector<int>&arr , int n ){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 and nums[j]>key){
            nums[j+1]=nums[j];
            j--
        }
        nums[j+1]=key;
    }
}