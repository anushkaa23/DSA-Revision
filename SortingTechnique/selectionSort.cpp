// Selection sort ##
// in selection short everytime the smallest number is picked and put on the right place in one iteration 

// ##code##
#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr,int n){
  //traverse the array
  for(int i=0;i<n-1;i++){
    int minInd=i;
    //find the minimum element in the remaining index
    for(int j=i+1;j<n;j++){
            if (arr[j] < arr[mini]) {
                mini = j; // Update mini if smaller element is found
            }
    }
    // Swap the found minimum element with the first element of unsorted part
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
  }
}
    
