#include<bits/stdc++.h>
using namespace std;


void merge(int arr[], int const let, int const mid, int const right){

     auto const subArrayOne = mid - left + 1;
     auto const subArrayTwo = right - mid;

     auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];


     for(auto i = 0; i < subArrayOne; i++){
        leftArray[i] = arr[left + 1];

     }

     for(auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = arr[mid + 1 + j];

     }
}
