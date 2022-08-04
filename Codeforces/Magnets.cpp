#include<bits/stdc++.h>
using namespace std;

int main(){

 int n, i;
 cin>> n;
 char str[n*2];

 for(i = 0; i < n*2; i++){

        cin>> str[i];

 }                  

 int counter = 1;

  for(int i =0; i < n*2; i++){

    if(str[i] == str[i+1]){

        counter++;
    }
  }

 cout << counter;

 return 0;
 }
