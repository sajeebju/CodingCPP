#include<bits/stdc++.h>
using namespace std;

int main(){

 int n, h;

 cin >> n >> h;

 int arr[n];

int sum1 = 0;
int sum2 = 0;

 for(int i = 0; i < n; i++){

    cin >> arr[i];
 }

  sort(arr, arr+n);


  for(int i = 0; i < n; i++){

     if(arr[i] <= h){

        sum1 = sum1 + 1;
     }
  }

  for(int i = n - 1; i >= 0; i--){

         if(arr[i] > h){

            sum2 = sum2 + 2;

         }

  }

int res = sum1 + sum2;

cout << res;

return 0;

}
