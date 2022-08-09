#include<iostream>
using namespace std;

void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

void bubbleSort(int arr[], int size){
  for(int i = 0; i < size ; i++){
    for(int j = i; j < size - i - 1; j++){
        swap(&arr[i], &arr[j]);
    }
  }
}
void printList(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
   int arr[] = {4,3,2,1};
   int n = sizeof(arr) / sizeof(arr[0]);
   bubbleSort(arr, n);
   printList(arr, n);
return 0;
}
