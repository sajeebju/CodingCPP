#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<ctime>

#define SIZE 300

using namespace std;

int binarySearch(int array[], int low, int high, int x) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] > x)
      return binarySearch(array, low, mid - 1, x);

    return binarySearch(array, mid + 1, high, x);
  }
  return -1;

}

int main(){

int randArray[SIZE];
for(int i = 0; i < SIZE; i++){
     randArray[i]=rand()%100;
}

// test binarySearch function

sort(randArray, randArray + SIZE);

 // sorting the random array

int number = 41;
int index = binarySearch(randArray, 0, SIZE - 1, number);

cout << "Found in " << index << " position" << endl << endl;;


// printing the array in sorted order

for(int i = 0; i <SIZE; i++){
    cout << randArray[i] << " ";
}

return 0;

}


