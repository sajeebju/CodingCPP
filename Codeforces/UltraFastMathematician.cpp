#include<bits/stdc++.h>

using namespace std;

int main(){

  char num1[100];
  char num2[100];

 cin>> num1;
 cin>> num2;

 for(int i = 0; i < strlen(num1); i++){

    if(num1[i] == num2[i]){
        cout << 0;
    }

    if(num1[i] != num2[i]){

        cout << 1;
    }
 }
return 0;
 }
