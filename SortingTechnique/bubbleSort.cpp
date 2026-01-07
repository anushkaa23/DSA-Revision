// Mastering Bubble Sort in Python. Python Data Structures and ...Bubble Sort is a simple sorting algorithm that repeatedly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order, causing larger elements to "bubble up" to their correct position.
// tc O(n^2)
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr , int n) {
    for (int i = n - 1; i >= 0; i--) {  //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]); //Swap arr[i] with arr[j+1]
                }
            }
        }
}