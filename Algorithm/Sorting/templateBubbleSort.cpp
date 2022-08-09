#include<bits/stdc++.h>
using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){
   for(int i = 0; i <n-1; i++){
    for (int j = n - 1; i < j; j--){
        if(arr[j] < arr[j - 1]){
            swap(arr[j], arr[j-1]);
        }
    }
   }

}

template<typename T>
void printArray(T arr[], int n){
   for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
   }

}

int main(){

   int arr[] = {5,4,6,3,2,8};
   int n = sizeof(arr) / sizeof(arr[0]);
   bubbleSort<int>(arr, n);
   printArray<int>(arr, n);

return 0;
}

